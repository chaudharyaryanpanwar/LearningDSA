#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
/*
    s = "ABC" 
    o/p : ABC ACB BAC BCA CAB CBA 
    Idea  : fix first character then second 
    A - Ab - Abc 
      -  Ac - Acb 
        
*/
using namespace std;

void printPermutation(string& str , int index = 0  ){ //TIME COMPLEXITY : n * n! or n!
    int n = str.length() ; 
    if (n == index){
        cout << str << endl  ; 
        return ;
    }
    for (int i=index ; i < n ; i++){
        swap(str[i] , str[index]);
        printPermutation(str, index +1 );
        swap(str[index] , str[i]);
    }
}

int main() {
    string str = "ABC";
    printPermutation(str );
    return 0;
}
