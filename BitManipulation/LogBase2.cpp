#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*

*/
int log2(int x){
    int res = 0 ; 
    while ( x > 1 ){
        x = x>>1 ; 
        res++ ; 
    }
    return res ; 
}
int main() {
    cout << log2(8);
    return 0;
}