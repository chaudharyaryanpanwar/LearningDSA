#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
    Given an array arr[] of integers, find out the maximum difference between any two elements 
    such that larger element appears after the smaller number. 

Examples : 


Input : arr = {2, 3, 10, 6, 4, 8, 1}
Output : 8
Explanation : The maximum difference is between 10 and 2.

Input : arr = {7, 9, 5, 6, 3, 2}
Output : 2
Explanation : The maximum difference is between 9 and 7.

*/
int maxDiff(vector <int > & arr ){ //TIME COMPLEXITY : N
    int n  = arr.size() ; 
    int minVal = arr[0] ; 
    int result = 0 ;
    for (int i =0 ;  i < n ; i++){
        if (arr[i]<minVal){
            minVal = arr[i];
        } else {
            result = max(result , arr[i] - minVal);
        }
    }
    return result ; 
}



int main() {
    vector <int> arr = {43, 91, 13, 67, 25, 82, 31, 49, 11, 58};
    cout << maxDiff(arr);
    return 0;
}