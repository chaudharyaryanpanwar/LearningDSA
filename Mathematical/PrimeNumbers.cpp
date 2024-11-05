#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool primeNumber(int n){
    if (n==2 || n==3)return true ; 
    else if (n%2 == 0 || n%3 == 0)return false ; 
    for (int i = 5 ; i*i <= n ; i=i+6){
        if (n%i==0 || n%(i+2)==0){
            return false ; 
        }
    }
    return true ; 
}
int main() {
    cout << primeNumber(113);
    return 0;
}