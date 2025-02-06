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
Given an array of integers, find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order. 

Examples:  

Input: arr[] = {1, 9, 3, 10, 4, 20, 2}
Output: 4
Explanation: 
The subsequence 1, 3, 4, 2 is the longest 
subsequence of consecutive elements

Input: arr[] = {36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42}
Output: 5
Explanation: 
The subsequence 36, 35, 33, 34, 32 is the longest 
subsequence of consecutive elements.
*/
int findLongestSubeseq(vector <int> & arr){
    int n = arr.size() ;
    int ans =0 ; 

    //hash all the array elemenets
    unordered_set <int> s ;
    for (int i= 0 ; i<n ; i++)s.insert(arr[i]);

    for (int i =0 ; i<n ; i++){
        int curr = arr[i] ;
        if (s.find(curr -1)== s.end()){
            int j = curr ; 
            while (s.find(j) != s.end()){
                j++;
            }
            ans = max(ans , j-curr);
        }
    }
    return ans ; 
}
int main() {
    vector <int> arr = { 1, 9, 3, 10, 4, 20, 2 }; 
    cout << findLongestSubeseq(arr) << endl;
    return 0;
}