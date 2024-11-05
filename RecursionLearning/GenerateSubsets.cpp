#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void subsets(string str , int index , string curr){ //TIME COMPLEXTIY : 2^n
    int n = str.length() ; 
    if (index == n){
        cout << curr << " ";
        return ; 
    }
    subsets(str , index +1  , curr + str[index]);
    subsets(str , index +1  , curr);
}
int main() {
    subsets("ABC" , 0 , "");
    return 0;
}