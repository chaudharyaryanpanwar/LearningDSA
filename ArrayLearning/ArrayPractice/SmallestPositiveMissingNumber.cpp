#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
You are given an integer array arr[]. 
Your task is to find the smallest positive number missing from the array.

Note: Positive number starts from 1. The array can have negative integers too.

Examples:

Input: arr[] = [2, -3, 4, 1, 1, 7]
Output: 3
Explanation: Smallest positive missing number is 3.
Input: arr[] = [5, 3, 2, 5, 1]
Output: 4
Explanation: Smallest positive missing number is 4.
Input: arr[] = [-8, 0, -1, -4, -3]
Output: 1
Explanation: Smallest positive missing number is 1.
*/
int smallestMissingNumber(vector <int> arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());

    for (int i = 1 ; i<n ; i++){
        int l = 0 , r = n-1 ; 
        bool found = false ; 
        while (l <= r){
            int mid = l + (r-l)/2 ; 
            if (arr[mid] == i){
                found = true ; 
                break;
            } else if (arr[mid]>i){
                r = mid-1 ;
            } else {
                l = mid + 1 ; 
            }
        }
        if (!found){
            return i; 
        }
    }

    return -1 ; 
}
int main() {
    vector <int> arr = {2, -3, 4, 1, 1, 7} ;
    cout << smallestMissingNumber(arr);
    return 0;
}