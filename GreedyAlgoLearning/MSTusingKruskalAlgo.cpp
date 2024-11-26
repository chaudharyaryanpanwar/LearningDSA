#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*

*/
bool sortingFunction(vector <int> a , vector <int> b){
    return a[2]>b[2];
}
int spanningTree(int V , vector <vector <int> > adj ){

    return 1 ; 
}
int main() {
    vector <vector <int>> adj = {{0,1,5},{0,2,1},{1,2,3}};
    sort(adj.begin() , adj.end() , sortingFunction);
    for (vector <int> a : adj){
        for (int i : a){
            cout << i << " ";
        }
        cout << endl ; 
    }
    return 0;
}