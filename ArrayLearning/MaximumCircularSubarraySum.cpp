#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
An array is called circular if we consider the first element as the next of the last element.                    
Example: arr[ ] ={1, 2, 3} 
The subarrays of this circular array can be: {1} {2} {3} {1, 2} {2, 3} {3, 1} {1, 2, 3} {2, 3, 1} {3, 1, 2}
Examples: 

Input: arr[] = {8, -8, 9, -9, 10, -11, 12}
Output: 22 
Explanation: Subarray 12, 8, -8, 9, -9, 10 gives the maximum sum, that is 22.

Input: arr[] = {10, -3, -4, 7, 6, 5, -4, -1} 
Output:  23 
Explanation: Subarray 7, 6, 5, -4, -1, 10 gives the maximum sum, that is 23.

Input: arr[] = {-1, 40, -14, 7, 6, 5, -4, -1}
Output: 52 
Explanation: Subarray 7, 6, 5, -4, -1, -1, 40 gives the maximum sum, that is 52.
*/

int maximumCircularSubarraySum(vector <int> &arr){
    int n= arr.size() ; 
        int sum =0  , maxSum = INT_MIN ; 
        int val = 0 , minSum = INT_MAX ; 
        int totalSum =0 ; 
        for (int i = 0 ; i<n ; i++){
            sum += arr[i];
            maxSum = max(sum , maxSum);
            if (sum<0)sum =0 ; 
            
            val += arr[i];
            minSum = min(val , minSum);
            if (val >0)val = 0; 
            
            totalSum += arr[i];
        }
        totalSum -= minSum ;
        if (totalSum > maxSum && maxSum >= 0){
            return totalSum ; 
        } else {
            return maxSum ; 
        }
}
int main() {
    vector <int> arr = {8, -8, 9, -9, 10, -11, 12} ;
    cout << maximumCircularSubarraySum(arr);
    return 0;
}