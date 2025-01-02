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
In this problem, we are given an array of unsorted integers . 
Our task is to find a peak element in the array.

A peak element is an element whose neighbors have value smaller than that of the element. 
Example : arr = [ 5, 6, 7, 8, 9, 10, 1, 2, 3  ]
output : 6 
explanation : 10 > 9 and 10 > 1 .
*/
int findPivot(vector <int> & arr){
    int n = arr.size() ; 
    int low = 0 , high = n-1 ; 
    while (low < high ){
        int mid = low + ( high - low ) / 2 ;
        if ( arr[mid] > arr[mid + 1 ] ){
            return mid ;
        }
        else if ( arr[mid]>arr[high] && arr[mid + 1 ] > arr[high]){
            low = mid +1  ;
        } else {
            high = mid ; 
        }
    }
    return -1 ; 
}
int main() {
    vector <int> arr = { 5, 6, 7, 8, 9, 10, 1, 2, 3 };
    cout << findPivot(arr) ; 
    return 0;
}