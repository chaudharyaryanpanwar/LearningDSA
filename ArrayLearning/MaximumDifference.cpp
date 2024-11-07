#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*

*/
int maxDiff(vector <int > & arr ){ //TIME COMPLEXITY : N
    int n = arr.size() ; 
    int res = arr[1] - arr[0];
    int minVal  = arr[0] ; 
    for (int i = 1 ; i<n ; i++){
        res = max(res , arr[i]-minVal);
        minVal = min(arr[i] , minVal);
    }
    return res ; 
}
int main() {
    vector <int> arr = {43, 91, 13, 67, 25, 82, 31, 49, 11, 58};
    cout << maxDiff(arr);
    return 0;
}