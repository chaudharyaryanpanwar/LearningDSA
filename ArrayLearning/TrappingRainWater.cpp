#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

/*
Input: arr[]   = {3, 0, 2, 0, 4}
Output: 7
Explanation: Structure is like below.
We can trap “3 units” of water between 3 and 2,
“1 unit” on top of bar 2 and “3 units” between 2 and 4.
*/

//NAIVE METHOD; 
int getWaterII(vector <int> & arr ){ // T : O(N^2) , S: 1
    int n = arr.size() ; 
    int res = 0 ; 
    for (int i =0 ; i<n ; i++){

        int lMax = arr[i];
        for (int j = 0; j<i ; j++){
            lMax = max(lMax , arr[j]);
        }

        int rMax = arr[i] ; 
        for (int j = i+1 ; j< n ; j++){
            rMax = max(rMax , arr[j]);
        }

        res += min(lMax , rMax) - arr[i];

    }
    return res ; 
}


//  EFFICIENT METHOD
int getWaterI(vector <int> &arr){
    int n = arr.size() ; 
    vector <int> lMax (n , 0);
    vector <int> rMax (n , 0);

    int res =0 ; 

    lMax[0] = arr[0];
    int maxVal  = arr[0];
    for (int i = 0 ; i< n ; i++){
        if (arr[i]>maxVal){
            lMax[i] = arr[i];
        }else {
            lMax[i] = maxVal ;
        }
    }

    rMax[n-1] = arr[n-1];
    maxVal = arr[n-1];
    for (int i = n-1 ; i>=0 ; i--){
        if (arr[i]>maxVal){
            rMax[i] =arr[i];
        } else {
            rMax[i] = maxVal ; 
        }
    }

    for (int i =0 ; i<n ; i++){
        res += min(lMax[i] , rMax[i]) - arr[i];
    }
    return res ;
}

int main() {
    vector <int> arr = {3, 0, 1, 2, 5};
    cout << getWaterII(arr) << endl;
    return 0;
}