#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/* 
A leader is an element in an array which is the 
maximum number when compared to all its right member
I/P : { 7 , 10 . 4 , 10 , 6, 5, 2}
O/P : { 2 , 5 , 6 , 10}
*/

void leaders(vector <int> &arr){
    int n = arr.size() ; 
    int max = arr[n-1];
    cout << max << " ";
    for (int i = n -2 ; i>=0 ; i--){
        if (arr[i]>max){
            max = arr[i];
            cout << arr[i] << " ";
        }
    }
}
int main() {
    vector <int> arr = {43, 91, 13, 67, 25, 82, 31, 49, 11, 58};
    leaders(arr);
    return 0;
}