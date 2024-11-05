#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

/* Rope of length n can only be cutted into three pieces A , B , C . Find max number of pieces*/
using namespace std;

int maxCuts(int n , int a , int b , int c){ //TIME COMPLEXITY : 3^n
    if (n==0)return 0 ; 
    else if (n<=-1) return -1 ;

    int res = max(maxCuts(n-a , a , b ,c) , max(maxCuts(n-b , a , b , c) , maxCuts(n-c  , a, b ,c)));

    if (res == -1)return -1 ; 
    return res+1 ; 
}

int main() {
    cout << maxCuts(23 , 11 , 9 , 12);
    return 0;
}