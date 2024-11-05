#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

/* Mean of array using recursion*/
int mean(vector <int> &arr, int index =0  , int sum =0 ){
    if (index == arr.size()){
        return sum / arr.size();
    }
    else return mean(arr , index+1 , sum + arr[index]);
}

int main() {
    vector <int> arr = {1 , 24, 34, 5, 56, 67, 67};
    cout << mean(arr);
    return 0;
}