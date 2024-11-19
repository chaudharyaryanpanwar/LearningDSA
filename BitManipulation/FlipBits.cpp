#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*

*/
int flipBits(int n ){
    int i = 1 << 31 ; 
    n = ~n ; 
    return n ; 
}
int main() {
    cout << flipBits(10);
    return 0;
}