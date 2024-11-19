#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
 Given an array arr[ ] of non-negative integers and an integer sum, 
 find a subarray that adds to a given sum.

Examples: 

Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
Output: Sum found between indexes 2 and 4
Explanation: Sum of elements between indices 2 and 4 is 20 + 3 + 10 = 33

Input: arr[] = {1, 4, 0, 0, 3, 10, 5}, sum = 7
Output: Sum found between indexes 1 and 4
Explanation: Sum of elements between indices 1 and 4 is 4 + 0 + 0 + 3 = 7

Input: arr[] = {1, 4}, sum = 0
Output: No subarray found
Explanation: There is no subarray with 0 sum
*/
pair<int , int > subarrayWithGivenSum(vector <int> & arr , int sum){
    int n = arr.size() ; 
    pair <int , int >result(-1 , -1);
    int currSum = 0 ; 
    int l =0 ; 
    int r=0 ; 
    while(l<=r && r<n){
        // if (currSum < sum){
        // currSum += arr[r++];
        // }
        currSum += arr[r++];
        if (currSum > sum){
            currSum -= arr[l++];
        } 
        if (currSum == sum){
            result.first = l ; 
            result.second = r ; 
            return result ; 
        }
        cout << currSum << " ";
    }
    cout << endl ; 
    return result ;
}
int main() {
    vector <int> arr = {1, 4, 20, 3, 10, 5};
    int sum = 33 ;
    pair<int , int > result = subarrayWithGivenSum(arr , sum);
    if (result.first != -1){
        cout << "Sum found between indexes " << result.first << " and " << result.second <<
        endl;
    } else {
        cout << "No subarray found" << endl;
    }
    return 0;
}