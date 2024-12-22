#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*
There is a sale going on , in which there are unlimited items with their IDs and their cost , the 
condition of sale is such that all the factor of ID of an item will be free with that item , 
now we have a given amount of money and have to return the maximum number of items that can be obtained for free
 and maximum total worth of those items 
input 
first line inputs N number of items
second line inputs N number of items with their ID 
third line inputs N number of items with their cost
fourth line inputs the amount of money
output
maximum number of items that can be obtained for free and maximum total worth of those items

here are two examples
Example 1

Input

7

4 9 11 13 15 5 25

1 4 2 6 3 7 8

10

Output

3 21

Explanation

There are 7 items with IDs {4, 9, 11, 13, 15, 5, 25} on sale. Their costs are {1, 4, 2, 6, 3, 7, 8}. Veda has 10 Rupees to spend on purchasing items in Buzz Day Sale.

If Veda buys the item with ID 15 in quantity of three, the total cost will be 3×3=9 (cost of ID 15 x quantity), which is less than 10. She will receive the item with ID 5 for free which is of worth 7. Thus, she will get the item with ID 5 with quantity three for free, resulting in a total worth of 7×3=21.

Since the quantity of free items is 3 and cost of free items is 21, print them as output.

Example 2

Input

5

11 24 3 12 7

7 11 15 9 4

17

Output

2 24

Explanation

There are 5 items with IDs {11, 24, 3, 12, 7} on sale. Their costs are {7 11 15 9 4}. Veda has 17 Rupees to spend on purchasing items in Buzz Day Sale.

If Veda buys item with ID 24, she will receive the items with ID 3 and ID 12 for free. No other purchase of combination will yield more free items. Therefore, she will get 2 free items, with a total worth of 24.

Since the quantity of free items is 2 and cost of free items is 24, print them as output.
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