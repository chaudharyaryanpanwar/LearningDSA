#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*

*/
void removeDuplicatesFromSortedArray(vector <int> & arr){
    int n = arr.size() ; 
    int k =1; 
    int prev = arr[0];
    for (int i = 1; i<n ; i++){
        if (arr[i] != prev) {
            prev = arr[i];
            swap(arr[k] , arr[i]);
            k++;
        }
    }
    arr.resize(k);
}


//driver code
int main() {
    vector <int> arr = {1 , 2, 2 , 2, 3, 4, 5 , 7 , 7, 7, 8, 9};
    removeDuplicatesFromSortedArray(arr);
    for (int i =0 ; i<arr.size() ; i++)cout << arr[i] << " ";
    return 0;
}