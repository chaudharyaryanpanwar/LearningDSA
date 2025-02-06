#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>

using namespace std;
/*

*/

string reverseString(string& str){
    int n = str.length() ; 
    for (int i= 0 ; i<n/2 ; i++){
        swap(str[i] , str[n-i-1]);
    }
    return str ;
}
int main() {
    string s = "Aryan Panwar" ; 
    cout << reverseString(s) << endl ;
    return 0;
}