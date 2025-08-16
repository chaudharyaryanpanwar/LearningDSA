#include <bits/stdc++.h>
#define ll long long int
using namespace std;
/*

*/
vector <ll> calculateSequenceIncreaseQueries(vector <pair <int , int >> arr , ll n ) {
    vector <ll> prefix1(n+2, 0) ; 
    vector <ll> prefix2(n+2, 0) ;
    for (ll i = 0 ; i<n ; i++){
        prefix1[arr[i].first]++ ;
        prefix1[arr[i].second+1]-- ;
        prefix2[arr[i].second+1] = -( arr[i].second - arr[i].first + 1 );
    }
    int m = arr.size() ; 
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    ll n ; cin >> n ; 
    ll m ; cin >> m ; 
    vector <pair <int , int >> arr(n) ; for(ll i =0 ; i<m ; i++){
        int first , second ; cin >> first >> second ;
        arr[i] = {first , second} ;
    }
    vector <ll> ans = calculateSequenceIncreaseQueries(arr , n ) ;
    fclose(stdin);
    fclose(stdout);
    return 0;
}