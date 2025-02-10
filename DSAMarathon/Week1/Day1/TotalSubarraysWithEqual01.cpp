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
 
 using namespace std;
 /*
 
 */
 int totalSybarraysWithEqual01(vector <int> arr){
    int n = arr.size() ; 
    unordered_map <int , int> mp ;
    mp[0] = 1 ;
    int count1 = 0 ; 
    int count0 = 0 ; 
    int ans = 0 ; 
    for (int i =0 ; i<n ; i++){
        if (arr[i] == 1)count1++ ;
        else count0++;
        int diff = count1  - count0 ; 
        if (mp.find(diff) != mp.end()){
            ans += mp[diff] ;
        }
        mp[diff]++;
    }
    return ans ; 
 }
 int main() {
    int n ; 
    cin >> n ; 
    vector <int> arr(n) ; 
    for (int i =0 ; i<n ; i++)cin >> arr[i] ; 
    cout << totalSybarraysWithEqual01(arr);
    return 0;
 }