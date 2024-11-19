#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*

*/
void ToggleBit(int n , int i ){
    int j = 1 << i ; 
    n = n ^ j ; 
    cout  << n ; 
}
int main() {
    ToggleBit(10 , 2);
    return 0;
}