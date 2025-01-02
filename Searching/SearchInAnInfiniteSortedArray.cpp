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
Search an element in an infintely long sorted array 
*/

int search(vector <int> & arr , int x ){ // T : logN , S : 1
    if (arr[0]==x)return 0 ; 
    int n = arr.size() ; 
    int l =1 ; 
    int r= 1 ; 
    while (arr[r]<x){
        l = r ; 
        r = r*2 ;
        if (r > n){
            r = n - 1 ; 
            break ; 
        }
    }
    cout << " l : " << l << " r : " << r <<endl ;
    while (l<=r){
        int m = (l+r)/2 ;
        if (arr[m]==x)return m ;
        else if (arr[m]<x)l = m+1 ;
        else r = m-1 ;
    }
    return -1 ; 
}

int main() {
    vector <int> arr = {1 , 10 , 15 , 20 , 40 , 60 , 80 , 100 , 200 , 500 , 1000};
    int x = 500 ; 
    cout << search(arr , x) << endl ;
    return 0;
}