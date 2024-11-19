#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
   Input: arr[]  = {1, 2, 0, 0, 0, 3, 6}
Output: 1 2 3 6 0 0 0

Input: arr[] = {0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9}
Output: 1 9 8 4 2 7 6 9 0 0 0 0 0
 
*/
void moveZerosToEnd(vector <int> & arr){
    int n = arr.size();
    int k = 0 ; 
    for (int i =0 ; i<n ; i++){
        if (arr[i]!=0){
            swap(arr[i] , arr[k++]);
        }
    }
}
int main() {
    vector <int> arr = {0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
    moveZerosToEnd(arr);
    for (int i : arr)cout << i <<  " ";
    return 0;
}