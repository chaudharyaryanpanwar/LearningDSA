#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
Input: arr[] = {1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1}
Output: 4

Input: arr[] = {0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1}
Output: 1

*/
int maxOne(vector <int> & arr){
    int n = arr.size() ; 
    int maxOnes = 0 ;
    int count = 0 ; 
    for (int i =0  ; i<n ; i++){
        if (arr[i]==1)count++;
        else count =0 ; 
        maxOnes = max(maxOnes , count);
    }
    return maxOnes ; 
}
int main() {
    vector <int> arr ={1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1};
    cout << maxOne(arr);
    return 0;
}