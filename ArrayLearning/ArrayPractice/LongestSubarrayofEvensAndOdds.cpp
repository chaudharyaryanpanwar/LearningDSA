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
You are given an array of size n. Find the maximum possible length of a subarray such that its elements are arranged alternately either as even and odd or odd and even .

Example 1:

Input:
n = 5
a[] = {10,12,14,7,8}
Output: 3
Explanation: The max length of subarray
is 3 and the subarray is {14 7 8}. Here 
the array starts as an even element and 
has odd and even elements alternately.
Example 2:

Input:
n = 2
a[] = {4,6}
Output: 1
Explanation: The array contains {4 6}. 
So, we can only choose 1 element as 
that will be the max length subarray.
*/

bool isOdd(int num){
    return (num & 1) ; 
}
int longestOddEvenSubarray(vector <int> & arr){
    int n= arr.size() ; 
    bool nextOdd = !isOdd(arr[0]) ; 
    int maxLen = 0 ; 
    int len = 1 ; 
    for (int i = 1 ; i<n ; i++){
        if ( isOdd(arr[i]) == nextOdd){
            len++;
            nextOdd = !nextOdd ; 
        } else {
            len = 1 ; 
        }
        maxLen = max(maxLen , len ) ; 
    }
    return maxLen ; 
}
int main() {
    vector <int> arr = {10,12,14,7,8} ; 

    cout << longestOddEvenSubarray(arr) ; 
    return 0;
}