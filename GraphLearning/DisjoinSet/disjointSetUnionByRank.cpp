#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class DisjoinSet
{
    vector<int> rank, parent;

public:
    DisjoinSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        else
            return parent[node] = findUPar(parent[node]);
    }

    void uninonByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
int main()
{
    DisjoinSet ds(7);
    ds.uninonByRank(1, 2);
    ds.uninonByRank(2, 3);
    ds.uninonByRank(4, 5);
    ds.uninonByRank(6, 7);
    ds.uninonByRank(5, 6);

    // if 3 and 7 are same or not
    if (ds.findUPar(3) == ds.findUPar(7))
        cout << "Same \n";
    else
        cout << "Not Same\n";

    ds.uninonByRank(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7))
        cout << "Same \n";
    else
        cout << "Not Same\n";
    return 0;
}