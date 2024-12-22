#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int rec(vector<vector<int>> &v, int n,int check){
    int count=0;
    for(int j=0;j<v[0].size();j++){
        if(v[n][j]==1){
        count++;
        }
    }
    if(check==1){
           if(count==3){
            return 1;
           }
           else{
            return 0;
           }
    }
    if(check==0){
        if(count<3){
            return 1;
        }
        else{
            return 0;
        }
    }
}
void fxn(vector<vector<int>> &v,int n,int check){
    for(int j=0;j<v[0].size();j++){
        if(v[j][n]!=INT_MIN){
            v[j][n]=check;
        }
    }
}
int main(){
    int n,m;
    cin>>n;
    cin>>m;
    vector<vector<int>> v(n,vector<int>(n,INT_MIN));
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a;
        cin>>b;
        v[a][b]=1;
        v[b][a]=1;
    }
    int k;
    cin>>k;
    vector<int> emp(n,1);
    // day 1
    k=k-n;
    //day 2 onwards;
    int days=1;
    while(k>0){
         for(int i=0;i<emp.size();i++){
            int store=rec(v,i,emp[i]);
            emp[i]=store;
            k=k-store;
         }
         for(int i=0;i<emp.size();i++){
            fxn(v,i,emp[i]);
         }
        days++;
    }
    cout<<days;
    return 0;

}