#include <bits/stdc++.h>
#define ll long long int
using namespace std;
/*
You are given a number line from 0 to n (inclusive), 
where n is a positive integer. There are m lights placed at different positions 
along this number line. Each light has a strength a and can light up a certain 
range of positions on the number line.

Your task is to determine how many points on the number line from 0 to n are 
well-lit. A point is considered well-lit if it is lit by at least b lights. 
The strength of each light means that the light will illuminate all positions 
from its position (inclusive) to the right, extending by a units.
*/
ll totalWellLitPoints(ll n , vector <ll> lights , ll a , ll b ){
    ll m = lights.size() ;
    vector <ll> numberLine(n , 0 ) ;
    for (ll i = 0 ; i < m ; i++){
        ll left = max( (ll)0 , lights[i]-a) ;
        ll right = min(n , lights[i]+a) ;
        numberLine[left]++ ;
        if (right+1<n)numberLine[right+1]-- ;
    }
    for (ll i = 1 ; i<n ; i++){
        numberLine[i] += numberLine[i-1] ;
    }
    ll ans =0 ; 
    for (ll i =0 ; i<n ; i++){
        if (numberLine[i]>=b)ans++ ;
    }
    return ans ; 
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    
    int n ; cin >> n ; 

    
    fclose(stdin);
    fclose(stdout);
    return 0;
}