#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
Given an array of integers of size 'n'. 
Our aim is to calculate the maximum sum of 'k' consecutive elements in the array.
 
Examples : 

Input  : arr[] = {100, 200, 300, 400}
         k = 2
Output : 700

Input  : arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20}
         k = 4 
Output : 39
We get maximum sum by adding subarray {4, 2, 10, 23}
of size 4.

Input  : arr[] = {2, 3}
         k = 3
Output : Invalid
There is no subarray of size 3 as size of whole
array is 2.
*/
int maximumSum(vector <int> &arr , int k){
    int n = arr.size() ; 
    int sum =0 ; 
    int maxSum = INT_MIN  ; 
    for (int i =0 ; i<k ; i++){
        sum += arr[i];
    }
    maxSum = max(sum , maxSum);
    for (int i = k ; i<n ; i++){
        sum = sum - arr[i-k] + arr[i];
        maxSum = max(sum , maxSum);
    }
    return maxSum ; 
}
int main() {
    vector <int> arr = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int k = 4 ; 
    cout << maximumSum(arr , k );
    
    return 0;
}