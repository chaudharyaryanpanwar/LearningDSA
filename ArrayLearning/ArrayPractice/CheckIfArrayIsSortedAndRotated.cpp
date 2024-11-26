#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
Given an array arr[] of N distinct integers, check if this array is Sorted (non-increasing or non-decreasing) and Rotated counter-clockwise. Note that input array may be sorted in either increasing or decreasing order, then rotated.
A sorted array is not considered as sorted and rotated, i.e., there should be at least one rotation.

Example 1:

Input:
N = 4
arr[] = {3,4,1,2}
Output: Yes
Explanation: The array is sorted 
(1, 2, 3, 4) and rotated twice 
(3, 4, 1, 2).
Example 2:

Input:
N = 3
arr[] = {1,2,3}
Output: No
Explanation: The array is sorted 
(1, 2, 3) is not rotated.
*/

bool isSortedAndRotated(int arr[] , int n ){
    int count1 = 0 ; 
    int count2 =0 ; 
    for (int i =0 ; i<n-1; i++){
        if (arr[i]>arr[i+1])count1++;
    }
    for (int i=1 ; i<n ; i++)if (arr[i]>arr[i-1])count2++;
    return (count1 == 1 || count2 ==1);
}
int main() {
    int arr[] =  {3,4,1,2};
    int n= 4 ; 
    cout << isSortedAndRotated(arr , n);
    return 0 ; 
}