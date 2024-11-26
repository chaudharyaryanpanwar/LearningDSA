#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*

*/
//Recursive
int lastIndex(vector <int> arr , int target , int l , int r){ //T : O(logN)
    int n = arr.size() ;
    if ( l >r)return -1 ; 
    int mid = l + ( r - l ) /2 ; 
    if (arr[mid] == target){
        if (mid == n-1 || arr[mid+1]!= target){
            return mid  ; 
        } else {
            return lastIndex(arr ,target , mid+1 , r);
        }
    } else if (arr[mid] > target){
        return lastIndex(arr , target , l , mid-1);
    } else {
        return lastIndex(arr , target , mid+1 , r);
    }
}

//Iterative Approach
int lastIndexIterative(vector <int> arr , int target){
    int n = arr.size() ; 
    int l = 0 , r = n - 1 ; 
    while (l <= r){
        int mid = l + ( r - l ) / 2 ; 
        if (arr[mid] == target){
            if (mid == n-1 || arr[mid+ 1]!= target){
                return mid ; 
            } else {
                l = mid + 1 ; 
            }
        } else if (arr[mid]>target){
            r = mid - 1 ;
        } else {
            l = mid + 1 ;
        }
    }
    return -1 ; 
}
int main() {
    vector <int> arr = { 1 , 2, 3, 4 , 4 , 4 , 5, 6 };
    int target = 4 ;
    cout << lastIndexIterative(arr , target) << endl ; 
    cout << lastIndex(arr ,target , 0 , arr.size() - 1);
    return 0;
}