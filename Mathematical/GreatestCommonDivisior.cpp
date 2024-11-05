#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int a , int b){
    // if (a<b) {
    //     swap(a,b);
    // }
    if (b==0)return a ; 
    else return gcd(b , a%b);
}
int main() {
    cout << gcd(13, 45);
    return 0;
}