#include <bits/stdc++.h>
#define ll long long int
using namespace std;
/*

*/
pair <int  , int > longestAP(vector <ll> arr){
    ll n = arr.size() ; 
    if (n<=2)return {0 , n} ;
    ll diff = 2 ; 
    pair <int , int> ans = {0 ,1}; 
    for (int i = 2 ; i<n ; i++){
        if (arr[i]-arr[i-1] == arr[i-1]-(i==1 ? 0 : arr[i-2])){
            diff++;
        } else {
            diff = 2 ; 
        }

        int len = ans.second - ans.first + 1;
        if (diff>len){
            ans.first = i-diff+1 ;
            ans.second = i ;
        }

    }
    return ans ;  
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);

    ll n ; cin >> n ; 
    vector <ll> arr(n) ; for(ll i =0 ; i<n ; i++)cin >> arr[i] ; 

    auto ans =  longestAP(arr) ;
    cout << ans.first ; 
    cout << endl <<ans.second <<endl ; 

    fclose(stdin);
    fclose(stdout);
    return 0;
}