#include <bits/stdc++.h>
#define ll long long int
using namespace std;
/*

*/
int maxSumOfGoodSubarray(vector <int> arr){
    int n = arr.size() ; 
    vector <int> prefix(n+1 , 0) ; 
    for (int i = 1 ; i<= n ; i++){
        prefix[i] = prefix[i-1] + arr[i-1] ;
        cout << prefix[i] << " " ;
    }cout << endl ; 

    int ans  =0 ; 
    unordered_map <int , int > mp ; 
    mp[0] = 0 ;
    for (int i =1 ; i<= n ; i++){
        if (mp.find(arr[i-1])!= mp.end()){
            ans = max(prefix[i] - prefix[mp[arr[i-1]]] , ans);
        } else {
            mp[arr[i-1]] = i ;
        }
        if (prefix[mp[arr[i-1]]]>prefix[i]){
            mp[arr[i-1]] = i ;
        }
    }
    return ans ; 
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n ; cin >> n ; 
    vector <ll> arr(n) ; for(ll i =0 ; i<n ; i++)cin >> arr[i] ;
    fclose(stdin);
    fclose(stdout);
    return 0;
}