#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
Given a sequence arr[ ] of size n, Write a function int equilibrium(int[] arr, int n) 
that returns an equilibrium index (if any) or -1 if no equilibrium index exists. 

What is an Equilibrium Point?
The equilibrium index of an array is an index such that the sum of elements at lower indexes 
is equal to the sum of elements at higher indexes. 

Examples: 

Input: A[] = {-7, 1, 5, 2, -4, 3, 0} 
Output: 3 //index of 2
3 is an equilibrium index, because: 
A[0] + A[1] + A[2] = A[4] + A[5] + A[6]

Input: A[] = {1, 2, 3} 
Output: -1 
*/
int naiveSol(vector <int> arr){ // T : O(N^2)
    int n = arr.size() ; 
    for (int i =0 ; i<n ; i++){
        int ls = 0  , rs = 0 ; 
        for (int j =0 ; j<i ; j++){
            ls += arr[j];
        }
        for (int j = i+1 ; j<n ; j++){
            rs += arr[j];
        }
        if (ls == rs){
            return i ; 
        }
    }
    return -1 ; 
}

int efficientSolution(vector <int> arr){
    int n = arr.size() ; 
    int rs =0 ; 
    for (int i =0 ; i<n ; i++){
        rs += arr[i] ;
    }
    int ls =0 ;
    for (int i =0 ; i<n ; i++){
        rs -= arr[i];
        if (ls == rs){
            return i ; 
        }
        ls += arr[i];
    }
    return -1 ; 
}
int main() {
    vector <int> arr = {-7, 1, 5, 2, -4, 3, 0} ;
    cout << naiveSol(arr) << endl;
    cout << efficientSolution(arr) << endl ; 
    return 0;
}