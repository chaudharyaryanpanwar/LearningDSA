#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*

*/
void swap(int a , int b){
    a ^=b ; 
    b ^= a; 
    a ^= b;
    cout << a << " : a " <<endl << b << " : b";
}
int main() {
    int a =5  , b=7 ; 
    cout << a << " : a " <<endl << b << " : b" << endl ;
    swap(a , b);
    return 0;
}