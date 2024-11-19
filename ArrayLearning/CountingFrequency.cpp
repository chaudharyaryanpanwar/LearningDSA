#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*

*/
void countingFreq(vector <int> &arr){
    int n = arr.size() ; 
    int count =1 ; 
    if (arr[1]==arr[0])count = 1 ; 
    else {
        cout << arr[0] << " : " << 1 << endl;  
    }
    for (int i = 1; i<n ; i++){
        if (arr[i] == arr[i-1]){
            count++;
        }
        else {
            cout << arr[i-1] << " : " << count << endl;
            count = 1 ; 
        }
    }
    if (count > 1){
    cout << arr[n-1] << " : " << count << endl;
    } else {
        cout << arr[n-1] << " : " << 1 << endl;
    }
}
int main() {
    vector <int> arr = {1 , 2,2 , 2, 3, 4, 5, 5, 5};
    countingFreq(arr);
    return 0;
}