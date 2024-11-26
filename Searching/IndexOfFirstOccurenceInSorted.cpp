#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*

*/
//Recursice approach
int firstIndex(vector <int > arr , int target , int l , int r){ //T : O(N) 
    int n = arr.size() ; 
    if ( l > r)return -1 ; 
    int mid = l + ( r- l ) / 2 ;
    if (arr[mid] == target){
        if (mid ==0 || arr[mid-1] != target){
            return mid ; 
        }else {
            return firstIndex(arr , target , l , mid -1 );
        }
    } else if (arr[mid] > target){
        return firstIndex(arr , target , l , mid -1);
    } else {
        return firstIndex(arr , target , mid + 1, r);
    }
}
//Iterative approach
int firstIndexIterative(vector <int> arr, int target){
    int n = arr.size() ; 
    int l = 0 ; 
    int r = n -1 ; 
    while ( l <= r){
        int mid = (l + r) / 2 ;
        if (arr[mid] == target){
            if (mid == 0 || arr[mid - 1] != target){
                return mid ;
            } else {
                r=mid-1 ; 
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
    cout << firstIndexIterative(arr , 4) << endl;
    cout << firstIndex(arr , 4 , 0 , arr.size() - 1);
    return 0;
}