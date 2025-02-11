#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>

using namespace std;

#define ll long long int

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll n; cin>>n;
    vector<ll> arr(n+1, 0);
    for(ll i=1;i<=n;i++) cin>>arr[i];

    vector<ll> pref(n+1, 0), pop(n+1, 0), fop(n+1, 0);
    for(ll i=1;i<=n;i++) pref[i]=pref[i-1]+arr[i];
    for(ll i=1;i<=n;i++) pop[i]=pop[i-1]+pref[i];

    fop[1]=1;
    fop[2]=((arr[2]-arr[1]==1) || (arr[2]-arr[1]==-1))?2:1;
    for(ll i=3;i<=n;i++){
        ll currdiff = arr[i]-arr[i-1];
        ll prevdiff = arr[i-1]-arr[i-2];
        if(currdiff==prevdiff && (currdiff==1 || currdiff==-1)) fop[i]=fop[i-1]+1;
        else if(currdiff==1 || currdiff==-1) fop[i]=2;
        else fop[i]=1;
    }

    ll ans = 0;
    for(ll i=1;i<=n;i++){
        ll r = i;
        ll l = i-fop[i]+1;
        ans += (r-l+1)*pref[r] - (pop[r-1] - (l-2>=0?pop[l-2]:0));
    }
    cout<<ans<<endl;
}