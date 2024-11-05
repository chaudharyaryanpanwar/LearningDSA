#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
 nCr = n-1Cr-1 + n-1Cr

 NCr = NCr-1 * (N-r+1) / r
*/

int nCr (int n , int r){
    if (n<r)return 0 ; 
    if ( n==1)return 1 ; 
    if ( r==1)return n ; 
    if (r==0)return 1 ; 
    return nCr(n-1 , r-1) + nCr(n-1,  r);
}

int main() {
    int n = 5 , r = 3 ; 
    cout << nCr(n , r);
    return 0;
}