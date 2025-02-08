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
1. Longest Substring Without Repeating Characters:
   - Description: Given a string, find the length of the longest substring without repeating characters.
   - Sample Test Case:
     Input: "abcabcbb"
     Output: 3
     Explanation: The answer is "abc", with the length of 3.

*/
int longestlen(string & str){
    int n = str.length() ; 
    if (n<=1)return n ; 
    
    unordered_set <char> seen ;
    int l = 0  , maxLen = 0 ; 

    for (int r =0 ; r<n ; r++){
        while(seen.find(str[r]) != seen.end()){
            seen.erase(str[l]);
            l++;
        }
        seen.insert(str[r]);
        maxLen = max(maxLen , r-l+1);
    } 
    return maxLen ; 
}
int main() {
    string str = "abcabcbb";
    cout << longestlen(str) << endl;
    return 0;
}