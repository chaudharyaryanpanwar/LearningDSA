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
Given a rod of length n inches and an array price[]. price[i] denotes the value of a piece of length i. The task is to determine the maximum value obtainable by cutting up the rod and selling the pieces.

Note: price[] is 1-indexed array.

Input: price[] =  [1, 5, 8, 9, 10, 17, 17, 20]
Output: 22
Explanation:  The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5 + 17 = 22.


Input : price[] =  [3, 5, 8, 9, 10, 17, 17, 20]
Output : 24
Explanation : The maximum obtainable value is 24 by cutting the rod into 8 pieces of length 1, i.e, 8*price[1]= 8*3 = 24.


Input : price[] =  [3]
Output : 3
Explanation: There is only 1 way to pick a piece of length 1.


*/
// Recursive Approach 
int cutRod(vector <int> &arr ,  int n  ){ 
    if(n == 0) return 0 ;
    int  q = INT_MIN ; 
    for (int i= 1 ; i<=n ; i++){
        q = max(q , arr[i-1] + cutRod(arr , n-i));
    }
    return q ; 
}
//using DYNAMIC PROGRAMMING
//MEMOIZATION APPROACH - top bottom approach
int cutRodDP1(vector <int> &arr , int n){
    vector <int> dp(n+1 , 0) ;
    if (n==0)return 0 ; 
    int  q = INT_MIN ; 
    for (int i = 1 ; i<=n ; i++){
        if (dp[i]!= 0)return dp[i];
        q  = max(q , arr[i-1] + cutRodDP1(arr , n-i)) ; 
        dp[i] = q ;
    }
    return q ; 
}

//using TABLE APPROACH - bottom up approach
int cutRodDP2(vector <int> &arr , int n){
    vector <int> dp (n+1 , 0) ;
    dp[0] = 0 ; 
    for (int i = 1 ; i<=n ; i++){
        int q = INT_MIN ;
        for (int j = 1 ; j<=i ; j++){
            q = max(q , arr[j-1] + dp[i-j]) ;
        }
        dp[i] = q ;
    }
    return dp[n] ; 
}
int main() {
    vector <int> arr = {1, 5, 8, 9, 10, 17, 17, 20} ; 
    cout << cutRod(arr , arr.size()) << endl ;
    cout << cutRodDP1( arr , arr.size()) << endl ; 
    cout << cutRodDP2(arr , arr.size() ) << endl ; 
    return 0;
}