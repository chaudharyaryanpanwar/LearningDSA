#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
Input: arr = [-2, -3, 4, -1, -2, 1, 5, -3]
Output: [4, -1, -2, 1, 5] , 7
Explanation: 
In the above input, the maximum contiguous subarray sum is 7 and the elements of the subarray are [4, -1, -2, 1, 5]

Input: arr = [-2, -5, 6, -2, -3, 1, 5, -6] 
Output: [6, -2, -3, 1, 5] , 7
Explanation: 
In the above input, the maximum contiguous subarray sum is 7 and the elements 
of the subarray are [6, -2, -3, 1, 5]
*/
int maximumSubarraySum(vector <int> & arr){
    int n = arr.size() ; 
    int maxSum = 0;
    int sum =0 ; 

    for (int i =0 ; i<n ; i++){
        sum = max(arr[i] , sum + arr[i]);
        maxSum  = max(maxSum , sum);
    }
    cout << endl ; 
    return maxSum ; 
}
int sol2(vector <int> &arr){
    int n = arr.size() ; 
    int sum =0 ; 
    int maxSum =0 ; 
    for (int i =0 ; i<n ; i++){
        sum += arr[i];
        if (sum < 0)sum =0 ; 
        maxSum = max(sum , maxSum );
    }
    return maxSum ; 
}
int main() {
    vector <int> arr = {-2, -5, 6, -2, -3, 1, 5, -6};
    cout << maximumSubarraySum(arr)<<endl;
    cout << sol2(arr);
    return 0;
}