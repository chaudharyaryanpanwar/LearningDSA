#include <bits/stdc++.h>
#define ll long long int
using namespace std;
/*
You are given an array of integers and a range [L, R] (both inclusive). 
Your task is to calculate the sum of all subarrays that are startend within the given range [L, R]
and ended at R.

A subarray is defined as a contiguous portion of the array. 
For example, if the array is [1, 2, 3], then the subarrays are [3] , [2, 3], and [1, 2, 3].

Input:
An integer n (1 ≤ n ≤ 10^5), the size of the array.
A list of integers arr[] of size n where each element arr[i] (−10^5 ≤ arr[i] ≤ 10^5).
Two integers L and R (1 ≤ L ≤ R ≤ n), representing the range of indices (inclusive) for the subarrays.
Output:
An integer representing the sum of all subarrays that are fully contained within the range [L, R].
Example 1:
Input:
n = 5
arr = [3, 5 , 1, 2, 3, 4]
L = 3
R = 5
Output:35
Explanation: The subarrays within the range [L = 2, R = 4] are:


[5] → sum = 3
[4, 5] → sum = 5
[3, 4, 5] → sum = 6
The total sum is 3 + 5 + 6 = 14.
*/
int calculateSumOfSubarraysWithingRange(vector<ll> arr, ll l, ll r)
{
    ll n = arr.size() ; 
    vector <ll> prefixSum(n+1 , 0) ; 
    vector <ll> pop(n+2 , 0) ; 
    for (ll i = 1 ; i<= n ; i++)prefixSum[i] = prefixSum[i-1] + arr[i-1] ; 
    for (ll i = 1 ; i <= n+1 ; i++)pop[i] = pop[i-1] + prefixSum[i-1] ;
    

    ll ans = 0 ;
    ans = (r-l+1)*prefixSum[r] - (pop[r] - pop[l-1]) ;
    return ans ; 
}
int naiveMethod(vector<ll> arr, ll l, ll r)
{
    ll n = arr.size();
    vector<ll> prefixSum(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
        cout << prefixSum[i] << " ";
    }
    cout << endl ; 
    ll ans = 0;
    for (ll i = l; i <= r; i++)
    {
        ans += prefixSum[r] - prefixSum[i-1];
    }
    return ans;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    ll l, r;
    cin >> l >> r;

    cout << naiveMethod(arr, l, r) << endl;
    cout << calculateSumOfSubarraysWithingRange(arr, l, r) << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}