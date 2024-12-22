#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
A Graph is a non-linear data structure consisting of vertices and edges. 
The vertices are sometimes also referred to as nodes and the edges are lines or arcs 
that connect any two nodes in the graph. More formally a Graph is composed of 
a set of vertices( V ) and a set of edges( E ). The graph is denoted by G(V, E).

Representations of Graph
Here are the two most common ways to represent a graph : 
For simplicity, we are going to consider only unweighted graphs .

Adjacency Matrix
Adjacency List

*/

//ADJACENCY MATRIX
void addEdgeMatrix(vector <vector <int>> &mat , int i , int j){
    mat[i][j] = 1 ; 
    mat[j][i] = 1 ; 
    //because it is an undirected graph.
}
void displayMatrix(vector <vector <int>> & mat){
    int V = mat.size() ; 
    for (int i =0  ; i < V ; i++){
        for (int j=0 ; j<V ; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl ;
    }
}

//ADJACENY LIST
void addEdgeList(vector <vector<int>> & list , int i , int j){
    list[i].push_back(j);
    list[j].push_back(i);
    //because it is an undirected graph.
}
void displayList(vector <vector <int>> &list ){
    int n = list.size() ; 
    for (int i = 0 ; i<n ; i++){
        cout << i << " : " ;
        for (int j = 0 ; j<list[i].size() ; j++){
            cout << list[i][j] << " " ;
        }
        cout << endl ; 
    }
}
int main() {
    int V = 4 ; 
    vector <vector <int>> mat(V , vector <int>(V , 0 ));
    addEdgeMatrix(mat , 0 , 1);
    addEdgeMatrix(mat, 0, 2);
    addEdgeMatrix(mat, 1, 2);
    addEdgeMatrix(mat, 2, 3);

    vector <vector <int>> list(V , vector <int>(0));
    addEdgeList(list , 0 , 1);
    addEdgeList(list, 0, 2);
    addEdgeList(list, 1, 2);
    addEdgeList(list, 2, 3);
    
    cout << "Adjacency Matrix Represenation " << endl ; 
    displayMatrix(mat);
    cout << "Adjacency List Representation " << endl ;
    displayList(list);
    return 0;
}