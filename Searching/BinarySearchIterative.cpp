#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*

*/
int binarySearch(vector <int> &arr , int target){
    int n= arr.size() ; 
    int l =0 , r = n-1 ; 
    while ( l <= r){
        int mid = l + ( r - l ) /2  ;
        if ( arr[mid] == target ){
            return mid ; 
        } else if (arr[mid] > target){
            r = mid - 1 ; 
        } else {
            l = mid + 1 ; 
        }
    }
    return -1 ; 
}
int main() {
    vector <int> arr = {43, 91, 13, 67, 25, 82, 31, 49, 11, 58};
    sort(arr.begin() , arr.end() );
    int target = 67;
    cout <<  binarySearch(arr, target);

    return 0;
}