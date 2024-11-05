#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

/*TRAILING ZEROES IN FACTORIAL
 //count number of 2 and 5 
 //count number of 5 only
*/

int trailingZeroes(int n ){
    int res =0 ; 
    for (int i =5 ; i<=n ; i=i*5){
        res = res+n/i;
    }
    return res ; 
}
int main() {
    cout << trailingZeroes(25);
    return 0;
}