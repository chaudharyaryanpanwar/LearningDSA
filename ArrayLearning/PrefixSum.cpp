#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
iven an array arr[] of size n, its prefix sum array is another array prefixSum[ ] of the same size, such that the value of prefixSum[i] is arr[0] + arr[1] + arr[2] … arr[i]. 

We need to create the prefix Array so that getsum() queries can be resolved in O(1) time.

Examples : 

Input  : arr[] = {10, 20, 10, 5, 15}
Output : prefixSum[] = {10, 30, 40, 45, 60}
Explanation : While traversing the array, update the element by adding it with its previous element.
prefixSum[0] = 10, 
prefixSum[1] = prefixSum[0] + arr[1] = 30, 
prefixSum[2] = prefixSum[1] + arr[2] = 40 and so on.
*/
vector <int> prefixArray(vector <int> & arr){
    int n =arr.size() ;
    vector <int> prefix (n);
    prefix[0] = arr[0];
    for (int i=1 ; i<n ; i++){
        prefix[i] = prefix[i-1]+arr[i];
    }
    return prefix ; 
}
int getSum(vector <int> prefix , int l , int r){
    if ( l== 0)return prefix[r];
    else return prefix[r] - prefix[l-1];
}
int main() {
    vector <int> arr = {43, 91, 13, 67, 25, 82, 31, 49, 11, 58};
    vector <int> prefix = prefixArray(arr);
    for (int i : prefix)cout << i << " ";
    cout << endl ; 
    cout << getSum(prefix , 2 , 4);
    return 0;
}