#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
Given an array a[ ] of N integers, the task is to find the length 
of the longest Alternating Even Odd subarray present in the array. 
 
Examples: 

Input: a[] = {1, 2, 3, 4, 5, 7, 9} 
Output: 5 
Explanation: 
The subarray {1, 2, 3, 4, 5} has alternating even and odd elements.

Input: a[] = {1, 3, 5} 
Output: 1
Explanation: 
There are only odd numbers, so we can count any one of them.

*/
bool isOdd(int num){
    return ((num & 1)== 1) ? true : false ;
}
int LongestEvenOddSubarray(vector <int> &arr){
    int n = arr.size() ; 
    int max_len = 1 ; 
    int len =1 ; 
    bool nextElementOdd = isOdd(arr[0])  ;
    for (int i= 1 ; i<n ; i++ ){
        if ((isOdd(arr[i]) && !nextElementOdd) || (!isOdd(arr[i]) && nextElementOdd)){
            len++;
            max_len = max(len , max_len);
            nextElementOdd = !nextElementOdd ; 
        }
        else {
        nextElementOdd = isOdd(arr[i]);
        len =1 ; 
        }
    }
    return max_len  ; 
}
int main() {
    vector <int> arr = {1, 2, 3, 4, 5, 7, 9} ;
    cout << LongestEvenOddSubarray(arr);
    return 0;
}