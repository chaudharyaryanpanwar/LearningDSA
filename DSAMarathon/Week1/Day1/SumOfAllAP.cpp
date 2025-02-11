#include <bits/stdc++.h>
#define ll long long int
using namespace std;
/*
Sum of All Arithmetic Progressions (AP)
Given an array of integers, your task is to calculate the sum of sums of all subarrays that 
form an arithmetic progression (AP). A subarray is considered an AP if the 
difference between consecutive elements of the subarray is constant.

Definition:
An arithmetic progression (AP) is a sequence of numbers in which the difference 
between consecutive terms is constant. For example, the sequence [3, 6, 9] is an AP 
with a common difference of 3, and [2, 4, 6, 8] is an AP with a common difference 
of 2.

Input:
An integer n (1 ≤ n ≤ 1000), the size of the array.
A list of n integers, arr[], where each element arr[i] (−10^5 ≤ arr[i] ≤ 10^5) 
represents an element of the array.
Output:
A single integer representing the sum of sums of all subarrays that form an 
arithmetic progression (AP).
*/
ll sumOfAP(vector <ll> arr){
    ll n = arr.size() ;
    vector<ll> prefixSum(n+1 , 0) , pop(n+1 , 0)  , fop(n+1 , 0);
    fop[1] = 1 ;
    fop[2] = 2 ; 
    for (ll i = 1 ; i<=n ; i++){
        prefixSum[i] = prefixSum[i-1] + arr[i-1] ;
        cout << prefixSum[i] << " ";
    }cout << endl ; 
    for (ll i = 1 ; i<=n ; i++){
        pop[i] = pop[i-1] + prefixSum[i] ;
        cout << pop[i] << " ";
    } cout << endl ; 
    for (ll i = 3 ; i<=n ; i++){
        ll currdiff = arr[i-1] - arr[i-2] ; 
        ll prevdiff = arr[i-2] - arr[i-3] ; 
        if (currdiff == prevdiff){
            fop[i] = fop[i-1] + 1 ; 
        } else {
            fop[i] = 2 ; 
        }
        cout<< fop[i] << " " ; 
    } cout << endl ; 
    ll ans = 0 ; 
    for (ll i = 1; i<=n ; i++){
        ll r = i  ;
        ll l = i - fop[i] + 1 ;
        ans += (r-l+1)*prefixSum[r] - (pop[r-1] - (l-2>=0 ? pop[l-2] : 0)) ;
    }
    return ans ; 
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    ll n ; cin >> n ; 
    vector <ll> arr(n) ; for(ll i =0 ; i<n ; i++)cin >> arr[i] ; 

    cout << sumOfAP(arr) << endl ;

    fclose(stdin);
    fclose(stdout);
    return 0;
}