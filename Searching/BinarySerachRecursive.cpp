#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*

*/
int binarySearch(vector <int> &arr , int target , int l , int r){
    int n = arr.size() ; 
    if(l <= r){
        int mid = (l + r) / 2 ;
        if(arr[mid] == target){
            return mid ; 
        } else if (arr[mid] > target){
            return binarySearch(arr , target , l , mid - 1) ;
        } else {
            return binarySearch(arr , target , mid + 1 , r);
        }
    } else {
        return -1 ; 
    }
}
int main() {
    vector <int> arr = {43, 91, 13, 67, 25, 82, 31, 49, 11, 58};
    sort(arr.begin() , arr.end());
    int target = 67 ; 
    cout << binarySearch(arr , target , 0 , arr.size() -1);
    return 0;
}