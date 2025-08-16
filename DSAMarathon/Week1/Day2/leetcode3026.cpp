#include <bits/stdc++.h>
#define ll long long int
using namespace std;
/*

*/
ll maximsumSubarraySum(vector <ll>  nums , int k){
    int n = nums.size() ; 
    vector <ll> prefix(n+1 , 0) ;
    unordered_map <ll , ll> mp ; 
    for (ll i = 1 ; i<= n ; i++){
        prefix[i] = prefix[i-1] + arr[i-1];
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}