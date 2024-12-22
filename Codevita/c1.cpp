#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*

*/

static bool cmp(pair<int,int>& p1, pair<int,int> &p2){
  if(p1.first==p2.first){
    return p1.second>p2.second;
  }
  else{
    return p1.first>p2.first;
  }
}
int  fact(int n,vector<int> &v){
    int ans=0;
    for(int i=1;i<n;i++){
        if(n%i==0){
            v.push_back(i);
            ans++;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    unordered_map<int,int> map;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
        map[x]=i;
    }
    vector<int> c;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        c.push_back(x);
    }
    int mon;
    cin>>mon;
    vector<pair<int,int>> f;
    for(int i=0;i<n;i++){
        vector<int> store;
        int siz=fact(v[i],store);
        int count=0;
        int price=0;
        for(int j=0;j<siz;j++){
           if(map.find(store[j])!=map.end()){
            count++;
            price+=c[map[store[j]]];
           }
        }
        int z=1;
        if(c[i]!=0){
            z=mon/c[i];
        }
        count=count*z;
        price=price*z;
        f.push_back({count,price});
        store.clear();
    }
    sort(f.begin(),f.end(),cmp);
    cout<<f[0].first<<" "<<f[0].second;
    return 0;
}