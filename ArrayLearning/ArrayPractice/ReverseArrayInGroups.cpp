#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
Given an array arr of positive integers. Reverse every sub-array group of size k.

Note: If at any instance, k is greater or equal to the array size, then reverse the entire array. 
You shouldn't return any array, modify the given array in place.

Examples:

Input: k = 3, arr= [1, 2, 3, 4, 5]
Output: [3, 2, 1, 5, 4]
Explanation: First group consists of elements 1, 2, 3. Second group consists of 4,5.
Input: k = 5, arr = [5, 6, 8, 9]
Output: [9, 8, 6, 5]
Explnation: Since k is greater than array size, the entire array is reversed.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)
*/
void reverse(vector <long long int> &arr , int l , int r){
    while ( l < r ){
        swap(arr[l++] , arr[r--]);
    }
    
}
void reverseInGroups(vector <long long int> & arr , int k){
    int n = arr.size() ; 
    int l = 0 ; 
    int r=k ; 
    
    for (int i = 0; i<n ; i+= k){
        int left = i ; 
        int right = min(i+k -1 , n-1);

        reverse(arr , left ,right);
    }
}
int main() {
    int k = 3;
    vector <long long int> arr = {1, 2, 3, 4, 5}  ; 
    reverseInGroups(arr , k);
    for (auto i : arr)cout << i << " " ;
    return 0;
}