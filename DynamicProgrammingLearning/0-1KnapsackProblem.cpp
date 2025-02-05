#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
Given N items where each item has some weight and profit associated with it and 
also given a bag with capacity W, [i.e., the bag can hold at most W weight in it].
The task is to put the items into the bag such that the sum of profits associated 
with them is the maximum possible. 

Note: The constraint here is we can either put an item completely into the bag or cannot put it at all 
[It is not possible to put a part of an item into the bag].

Examples:

Input: N = 3, W = 4, profit[] = {1, 2, 3}, weight[] = {4, 5, 1}
Output: 3
Explanation: There are two items which have weight less than or equal to 4. 
If we select the item with weight 4, the possible profit is 1. 
And if we select the item with weight 1, the possible profit is 3. 
So the maximum possible profit is 3. Note that we cannot put both the items with 
weight 4 and 1 together as the capacity of the bag is 4.

Input: N = 3, W = 3, profit[] = {1, 2, 3}, weight[] = {4, 5, 6}
Output: 0
*/

// Recursion Approach
int knapsackRecursion(int W , vector <int> weight , vector <int> profit , int n ){
    if(n == 0 || W == 0){
        return 0 ; 
    }
    if (weight[n-1]>W){
        return knapsackRecursion(W , weight , profit , n-1);
    } else {
        return max(knapsackRecursion(W, weight , profit , n-1) , profit[n-1]+knapsackRecursion(W-weight[n-1] , weight , profit , n-1 ));
    }
}
// Memoization Approach
// Top - Bottom Approach
int knapsackMemoization(int W , vector <int> weight , vector <int> profit , int index , vector < vector <int>> &dp ){
    if (index < 0 || W<= 0){
        return 0 ; 
    }
    if (dp[index][W] != -1 ){
        return dp[index][W];
    }
    if (weight[index]>W){
        dp[index][W] = knapsackMemoization(W , weight , profit , index - 1, dp);
        return dp[index][W];
    } else {
        dp[index][W] = max(profit[index] + knapsackMemoization(W - weight[index] , weight , profit , index -1 , dp) , 
                                           knapsackMemoization(W , weight ,profit , index -1 , dp ) );
        return dp[index][W];
    }
}
int callerKnapsackMemoization(int W , vector <int> weight , vector <int> profit ,  int n){
    vector <vector <int>> dp ( n , vector <int> ( W + 1 , -1));
    return knapsackMemoization(W , weight , profit , n -1 , dp);
}

// Tabulation Approach
int knapsackTabulation(int W , vector <int> weight , vector <int> profit  , int n ){
    vector <vector <int> > dp ( n + 1 , vector <int> (W+1 , -1));

    for (int i =0 ; i<= n ; i++){
        for (int j = 0 ; j<=W ; j++){
            if ( i == 0 || j == 0){
                dp[i][j] = 0 ; 
            } else if (weight[i-1]<= j){
                dp[i][j] = max(profit[i-1]+dp[i-1][j-weight[i-1]] , 
                               dp[i-1][j]) ;
            } else {
                dp[i][j] = dp[i-1][W];
            }
        }
    }
    return dp[n][W];
}
int main()
{
    vector <int> profit = { 60, 100, 120 };
    vector <int > weight = { 10, 20, 30 }; 
    int W = 50;
    int n = profit.size() ; 
    // cout << knapsackRecursion(W, weight, profit, n)<<endl ;
    // cout << callerKnapsackMemoization(W , weight , profit , n )<<endl ; 
    cout << knapsackTabulation(W , weight , profit , n);
    return 0;
}