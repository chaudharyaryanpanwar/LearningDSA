#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#define ll long long int
using namespace std;
/*

*/
int longestSubarrayWithEqual01(vector <ll> arr){
    int n = arr.size();
    unordered_map <int , int> mp;
    int count1 = 0; 
    int count0 = 0 ; 
    int ans  = 0; 
    for (int i = 0 ; i<n ; i++){
        if (arr[i]==0)count0++;
        else count1++;
        int diff = count1 - count0;
        if (mp.find(diff) == mp.end()){
            mp[diff] = i;
        }
        else{
            ans = max(ans, i - mp[diff]);
        }
    }
    return ans ; 
}
int main() {
    int n;
    cin >> n;
    vector<ll> arr(n, 0);
    for (int i = 0; i < n; i++)cin >> arr[i];
    cout << longestSubarrayWithEqual01(arr);

    return 0;
}