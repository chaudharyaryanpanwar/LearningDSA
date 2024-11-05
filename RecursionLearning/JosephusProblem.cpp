#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

/*JOSEPHUS PROBLEM 
    N peopel standing in a cricle , K indicates k-1 skipped and then 
    kth is killed.
    Task is to choose the safe place which is the last survival of all.
*/
using namespace std;

int jos(int n , int k ){ //TIME COMPLEXITY : n
    if (n==1)return 0 ; 
    return (jos(n-1,k)+k)%n ; 
}

int main() {
    cout << jos(5, 2);
    return 0;
}