#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;
/*
    Given an integer array arr[], print all distinct elements from this array. The given array may contain duplicates and the output should contain every element only once.

Examples: 

Input: arr[] = {12, 10, 9, 45, 2, 10, 10, 45}
Output: {12, 10, 9, 45, 2}


Input: arr[] = {1, 2, 3, 4, 5}
Output: {1, 2, 3, 4, 5}


Input: arr[] = {1, 1, 1, 1, 1}
Output: {1}


*/

void distinctElements(vector <int> & arr){
     unordered_set<int> st ;
     for (int i : arr){
        st.insert(i);
     }
     for (int i : st)cout << i << " ";
}

int main() {
    vector <int> arr = {12, 10, 9, 45, 2, 10, 10, 45} ; 
    distinctElements(arr);
    return 0;
}