#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*

*/
int divide(int n ){
    return n >> 1 ; 
}
int multiply(int n ){
    return n << 1 ; 
}
int main() {
    cout << divide(5)<<endl;
    cout << multiply(5);
    return 0;
}