#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
    LINEAR SEARCH 
*/

int linearSearch(int arr[] , int n , int target){
    for (int i= 0 ; i<n ; i++){
        if(arr[i] == target){
            return i; 
        }
    }
    return -1 ; 
}
int main() {
    int arr[] = {43, 91, 13, 67, 25, 82, 31, 49, 11, 58};
    int n = 10;
    int target = 67;

    cout << linearSearch(arr ,n , target);
    return 0;
}