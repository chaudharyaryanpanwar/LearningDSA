#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*

*/
int firstIndex(vector <int > arr , int target , int l , int r){ //T : O(logN) 
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
int countOccurence(vector <int > array , int target){
    int first = firstIndex(array , target , 0 , array.size() -1);
    if (first  == - 1) return -1 ; 
    else return (lastIndex(array , target , 0 , array.size() - 1) - first + 1 );
}

int main() {
    vector <int> arr = { 1 , 2, 3, 4 , 4 , 4 , 5, 6 };
    int target = 4 ;
    cout << countOccurence(arr , target) << endl;
    return 0;
}