#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*

*/
bool isOdd(int num ){
   // If the last bit is 1, the number is odd; otherwise, it's even.
    return num & 1 ;
}
int main() {
    int n1 = 14 , n2 = 7 ; 
    cout << isOdd(n1)<<endl << isOdd(n2);
    return 0;
}