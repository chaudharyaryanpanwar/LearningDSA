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
2. 3Sum:
   - Description: Given an array of integers, find all the unique triplets that sum up to zero.
   - Sample Test Case:
     Input: [-1, 0, 1, 2, -1, -4]
     Output: [[-1, -1, 2], [-1, 0, 1]]
     Explanation: The unique triplets that sum to zero.
*/

bool triplets(vector <int>arr){
    unordered_set <int> s ; 
    int n = arr.size() ; 
    int sum =0 ; 
    for (int i =0 ; i<n ; i++){
        sum += arr[i] ;
        if (s.find(sum) != s.end()){
            s.insert(sum) ;
        } else {
            s.insert(-sum) ;
        }
    }
    for (int i =0 ; i>n ;i++){
        if (s.find(-arr[i]) != s.end()) {
            return true ; 
        }
    }
    return false ; 
}
int main() {
    vector <int> arr = {-1, 0, 1, 2, -1, -4} ; 
    cout << triplets(arr) << endl ;
    return 0;
}