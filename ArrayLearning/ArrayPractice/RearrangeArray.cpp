#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
    Given an array of elements of length n, ranging from 0 to n – 1. All elements may not be present in the array. If the element is not present then there will be -1 present in the array. Rearrange the array such that arr[i] = i and if i is not present, display -1 at that place.

Examples: 

Input: arr[] = [-1, -1, 6, 1, 9, 3, 2, -1, 4, -1]
Output: [-1, 1, 2, 3, 4, -1, 6, -1, -1, 9]
Explanation: In range 0 to 9, all except 0, 5, 7 and 8 are present. Hence, we print -1 instead of them.


Input: arr[] = [0, 1, 2, 3, 4, 5] 
Output: [0, 1, 2, 3, 4, 5]
Explanation: In range 0 to 5, all number are present.
*/

//NAIVE SOLUTION : T : N^2 , S  : 1
void naive(vector <int> & arr){
    int n = arr.size() ; 
    for (int i=0 ; i< n ; i++){
        for (int j =0 ; j<n ; j++){
            if (arr[j] == i){
                swap(arr[j] , arr[i]) ; 
                break ; 
            }
        }
    }

    //Put -1 to all the indexes where the same indexes are not present
    for (int i =0 ; i<n ; i++){
        if (arr[i]!= i )arr[i] = -1 ; 
    }
}

//BETTER APPROACH : T : N , S : N
void better(vector <int> arr){
    int n = arr.size() ;
    vector <int> temp (n , -1);

    for (int i =0 ; i < n ; i++){
        if (arr[i]!= -1 && arr[i] < n){
            temp[arr[i]] = arr[i];
        }
    }

    for (int i  : temp)cout <<i << " ";
    cout << endl ; 
}
int main() {
    vector <int> arr = {43, 91, 3, 67, 25, 82, 31, 49, 8, 58};
    better(arr);
    naive(arr);
    for (int i : arr)cout << i << " ";
    return 0;
}