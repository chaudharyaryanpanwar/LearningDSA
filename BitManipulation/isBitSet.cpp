#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*

*/
bool isBitSet(int n , int i ){
    return n & (1 << i);
}
int main() {
    cout << isBitSet(10 , 0);
    return 0;
}