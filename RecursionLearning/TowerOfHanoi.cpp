#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

 void toh(int n , char a , char b , char c){ //TIME COMPLEXITY : 2^n
    if (n==1){
        cout << "Move 1 from " << a << " to " << c << endl;
        return ;
    }
    toh(n-1 , a , c, b);
    cout << "Move "<<n<<" from "<<a<< " to " << c << endl;
    toh(n-1 , b , a, c);
 }
int main() {
    toh(5 , 'A' , 'B' , 'C');
    return 0;
}