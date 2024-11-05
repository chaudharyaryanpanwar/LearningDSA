#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

// a*b = lcm(a,b) * gcd(a,b)
//lcm(a, b) = (a*b) /gcd(a,b)
int gcd(int a , int b){
    if (b==0)return a  ; 
    else return gcd(b , a%b);
}
int lcm(int a , int b ){
    return (a*b)/gcd(a,b);
}
int main() {
    cout << lcm(4 , 5);
    return 0;
}