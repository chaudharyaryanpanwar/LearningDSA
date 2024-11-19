#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
    Left Rotate Array
    I/P = {1 ,43 , 54, 7, 67, 87} , left rotate by 2 places
    O/P = {67, 87, 1, 43, 54 ,7 }
*/
void rotateArr(vector <int> & arr , int l , int r){
    while (l < r){
        swap(arr[l++] , arr[r--]);
    }
} 
void leftRotate(vector <int> &arr , int d){ // T : O(N) , S  : 1
    int n = arr.size() ; 
    rotateArr(arr , 0 , n-1);
    rotateArr(arr , 0 , d-1);
    rotateArr(arr , d , n-1);
}
int main() {
    vector <int> arr = {43, 91, 13, 67, 25, 82, 31, 49, 11, 58};
    int d = 3 ; 
    leftRotate(arr , d);
    for (int i = 0 ; i < arr.size() ; i++)cout << arr[i] << " ";
    return 0; 
}