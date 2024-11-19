#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*

*/
void clearBit(int n , int i ){
    int j = 1 << i ;
    n = n & ~(1<<i);
    cout << n ; 
}

int main() {
    clearBit(10 , 1);
    return 0;
}