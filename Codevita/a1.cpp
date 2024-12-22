#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;
/*

*/

int relationMatrix(vector<vector<int>> &matrix, int n, int c, int size) {
    int freq = 0;
    for (int j = 0; j < size; j++) {
        if (matrix[n][j] == 1) {
            freq++;
        }
    }
    if (c == 1){
        if (freq == 3) return 1;
        else  return 0;
    }
    if (c == 0){
        if (freq < 3) return 1;
        else return 0;
    }
    return -1 ;
}
void updateMatrix(vector<vector<int>> &matrix, int n, int c, int size) {
    for (int i = 0; i < size ; i++) {
        if (matrix[i][n] == INT_MIN)continue ; 
        else  matrix[i][n] = c ;
    }
}

int main() {
    int n, m;
    cin >> n ;
    cin >> m ; 
    vector<vector<int>> matrix(n, vector<int>(n, INT_MIN));
    for (int i = 0; i < m; i++) {
        int j,k;
        cin >> j >> k;
        if (j >= 0 && j < n ) {
            if (k >= 0 && k < n) {
                matrix[j][k] = 1;
                matrix[k][j] = 1;
            }
        }
    }
    int j;
    cin >> j;
    vector<int> employee(n, 1);
    j = j - n;
    int totalDays = 1;
    while (j>0){
        for (int i = 0; i < n; i++) {
            int store = relationMatrix(matrix, i, employee[i], n);
            employee[i] = store;
            j -= store;
        }
        for (int i = 0; i < n; i++) {
            updateMatrix(matrix, i, employee[i], n);
        }
        totalDays++;
    }
    cout << totalDays ;
    return 0;
}