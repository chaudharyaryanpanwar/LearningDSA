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
Given an array of positive and negative numbers, 
find if there is a subarray (of size at-least one) with 0 sum.

Examples : 
Input: {4, 2, -3, 1, 6}
Output: true 
Explanation:
There is a subarray with zero sum from index 1 to 3.

Input: {4, 2, 0, 1, 6}
Output: true

Explanation :  

The third element is zero. A single element is also a sub-array. 

Input: {-3, 2, 3, 1, 6}
Output: false
*/
bool subArrayExists(vector <int> arr ){
    int n = arr.size() ; 
    int sum =0 ; 
    unordered_set <int> s ; 
    for (int i= 0 ; i<n ; i++){
        sum += arr[i];
        if (sum == 0 || s.find(sum) != s.end()){
            return true ; 
        }
        s.insert(sum);
    }
    return false ; 
}
int main() {
    vector <int> arr = {4, 2, 0, 1, 6} ;
    if (subArrayExists(arr)){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}