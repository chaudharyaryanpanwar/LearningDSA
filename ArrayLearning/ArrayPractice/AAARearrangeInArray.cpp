#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
Given an array arr[] of size N where every element is in the range from 0 to n-1. 
Rearrange the given array so that the transformed array arrT[i] becomes arr[arr[i]].

NOTE: arr and arrT are both same variables, representing the array before and after transformation respectively.

Example 1:

Input:
N = 2
arr[] = {1,0}
Output: 0 1
Explanation: 
arr[arr[0]] = arr[1] = 0
arr[arr[1]] = arr[0] = 1
So, arrT becomes {0, 1}
Example 2:

Input:
N = 5
arr[] = {4,0,2,1,3}
Output: 3 4 2 0 1
Explanation: 
arr[arr[0]] = arr[4] = 3
arr[arr[1]] = arr[0] = 4
arr[arr[2]] = arr[2] = 2
arr[arr[3]] = arr[1] = 0
arr[arr[4]] = arr[3] = 1
and so on
So, arrT becomes {3, 4, 2, 0, 1}

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/

//IDEA
/*
Idea is to use the logic  “Dividend = Divisor × Quotient + Remainder”. We will do arr[i] += (arr[arr[i]] % n) * n. 
[ n is greater than all the array elements ] 
How does expression "arr[i] += (arr[arr[i]] % n) * n" work ? 
The purpose of this expression is to store two elements at index i. 
arr[arr[i]] is stored as a multiplier and "arr[i]" is stored as the remainder. 
For example in {3 1 0 2 4 5 6 7 8}, n is 9 and we store 21 at index 0. 
By using value 21, we can get the original element(arr[0]) as 21%9 = 3 
and the new element(arr[arr[0]) as 21/9 = 2 
hence here we achieved the purpose of storing 2 values at a single index.
*/


void rearrangeInArray(vector <int> &arr){ //T : O(N) , S : O(1)
    int n = arr.size() ; 
    for (int i =0 ; i<n ; i++){
        arr[i] = arr[i] + (arr[arr[i]]%n)*n ; 
    }
    for (int i = 0 ; i<n ; i++){
        arr[i] = arr[i]/n ; 
    }
}
int main() {
    return 0;
}