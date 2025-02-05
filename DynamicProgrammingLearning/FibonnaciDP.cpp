#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
The Fibonacci sequence is a sequence where the next term is the sum of the previous two terms. 
The first two terms of the Fibonacci sequence are 0 followed by 1. The Fibonacci sequence: 
0, 1, 1, 2, 3, 5, 8, 13, 21

Example:

Input: n = 2
Output: 1 
Explanation: 1 is the 2nd number of Fibonacci series.


Input: n = 5
Output: 5
Explanation: 5 is the 5th number of Fibonacci series
*/


//DYNAMIC PROGRAMMING   
//Expected Apporach - 1
//Memorization Approach  , T : O(N) , S : O(N)
int solutionI(int n , vector <int> &memo){
    if (n<=1)return n ; 
    if (memo[n] != -1){
        return memo[n];
    }
    memo[n] = solutionI(n-1 , memo )  + solutionI(n-2 , memo);
    return memo[n];
}
int callSolutionI(int n){
    vector <int> memo(n+1 , -1);
    return solutionI(n , memo);
}

//DYNAMIC PROGRAMMING
//Expected Apporach - 2
//Tabulation Approach , T : O(N) , S : O(N)
int solutionII(int n){
    if (n<=1)return n ; 
    vector <int> dp(n+1) ; 
    //initialize the first two elements of the array
    dp[0] = 0 ;
    dp[1] = 1 ; 

    for (int i = 2 ; i<= n ; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }

    return dp[n];
}


//DYNAMIC PROGRAMMING
//Expected Apporach - 3
//Tabulation Approach , T : O(N) , S : O(1)
int solutionIII(int n){
    if (n<=1)return n ;
    int a = 0 ; 
    int b = 1 ; 
    int sum ; 
    for (int i =2 ; i<= n ; i++){
        sum = a + b;
        a = b ;
        b = sum ; 
    }
    return b ; 
}

int main() {
    int n = 8 ; 
    cout << callSolutionI(n) << endl;
    cout << solutionII(n) << endl;
    cout << solutionIII(n) << endl ; 
    return 0;
}