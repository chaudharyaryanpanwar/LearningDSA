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
Given an array arr of non-negative numbers. The task is to find the first equilibrium point in an array. The equilibrium point in an array is an index (or position) such that the sum of all elements before that index is the same as the sum of elements after it.

Note: Return equilibrium point in 1-based indexing. Return -1 if no such point exists. 

Examples:

Input: arr[] = [1, 3, 5, 2, 2]
Output: 3 
Explanation: The equilibrium point is at position 3 as the sum of elements before it (1+3) = sum of elements after it (2+2). 
Input: arr[] = [0, 1, 0]
Output: 2
Explanation: Since sum all the elements before 1 and after 1 are same, so index 2 is equillibrium.
Input: arr[] = [1, 2, 3]
Output: -1
Explanation: There is no equilibrium point in the given array.
*/
int ePoint(vector <int> & arr){  
//T : O(N) 
//S : O(1)
    int n = arr.size() ; 
    int l = 0 ; 
    int lSum = arr[0] ; 
    int r = n-1 ; 
    int rSum = arr[n-1] ; 
    while(l<r){
        if (lSum==rSum){
            if (l+1 == r-1)return l+1 ; 
            else {
                l++;
                lSum += arr[l];
            }
        }
        else if (lSum < rSum){
            l++ ;
            lSum += arr[l];
        } else {
            r-- ; 
            rSum += arr[r] ; 
        }
        cout << " l lSum r rSum " << l << " " << lSum << " " << r << " " << rSum << endl ; 
    }
    return  -1 ; 
}
//using prefix method
int ePoint2(vector <int> & arr){
    int n = arr.size() ; 
    for (int i =1 ; i<n ; i++){
        arr[i] += arr[i-1]; 
    }
}
int main() {
    vector <int> arr = {1, 3, 5, 2, 2}  ;
    // 1 4 9 11 13
    cout << ePoint(arr) << endl ;
    return 0;
}