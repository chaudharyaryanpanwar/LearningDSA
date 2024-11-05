#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void binaryEquivalent(int n ){
    if (n==0)return ; 
    binaryEquivalent(n/2);
    cout << (n%2) << " ";
}
int main() {
    binaryEquivalent(7);
    return 0;
}