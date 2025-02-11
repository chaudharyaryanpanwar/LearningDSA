#include <bits/stdc++.h>
#define ll long long int
using namespace std;
/*
You are given an array of integers, and your task is to calculate the 
sum of sums of all the subarrays in the array.

A subarray is defined as a contiguous portion of the array. 
For example, if the array is [1, 2, 3], the subarrays are:

[1]
[2]
[3]
[1, 2]
[2, 3]
[1, 2, 3]
Input:
An integer n (1 ≤ n ≤ 10^5), the size of the array.
A list of integers arr[] of size n where each element arr[i] (−10^5 ≤ arr[i] ≤ 10^5).
Output:
An integer representing the sum of sums of all subarrays of the given array.
Example 1:
Input:
n = 3
arr = [1, 2, 3]
Output:20
Explanation: The subarrays are:

[1] → sum = 1
[2] → sum = 2
[3] → sum = 3
[1, 2] → sum = 3
[2, 3] → sum = 5
[1, 2, 3] → sum = 6
The sum of these sums is 1 + 2 + 3 + 3 + 5 + 6 = 20.
*/

//less optimized but usign PREFIX SUM
ll sumOfSumOfAllSubarrays(vector <ll> arr ){
    ll n = arr.size() ; 
    vector <ll> prefixSum(n+1 , 0) ;
    vector <ll> pop(n+1 , 0) ; 
    for (ll i = 1 ; i<=n ; i++){
        prefixSum[i] = prefixSum[i-1] + arr[i-1];
        cout << prefixSum[i] << " ";
    } cout << endl ; 
    for (ll i =1 ; i<=n+1 ; i++){
        pop[i] = pop[i-1] + prefixSum[i] ;
        cout << pop[i] << " ";
    }cout <<endl ; 


    ll ans = 0 ; 
    for (ll i =1 ; i<=n ; i++){
        ans += (i+1)*prefixSum[i] - pop[i] ;
        cout << ans << " ";
    } cout << endl ; 
    return ans ; 
}

// optimized code :  CONTRIBUTION METHOD
ll sumOfSumOfAllSubarraysOptimized(vector <ll> arr){
    ll n = arr.size() ; 
    ll ans = 0 ; 
    for (ll i = 0 ; i<n ; i++){
        ans += arr[i]*(i+1)*(n-i) ;
    }
    return ans ; 
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);

    ll n; cin >> n ; 
    vector <ll> arr(n); for (ll i =0 ; i<n ; i++)cin >> arr[i] ;

    cout << sumOfSumOfAllSubarrays(arr) << endl ;
    cout << sumOfSumOfAllSubarraysOptimized(arr) ;

    fclose(stdin);
    fclose(stdout);
    return 0;
}