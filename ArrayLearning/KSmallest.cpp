#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
    Given an array arr[] of N distinct elements and a number K, where K is smaller than the size of the array. Find the K’th smallest element in the given array.

Examples:

Input: arr[] = {7, 10, 4, 3, 20, 15}, K = 3 
Output: 7


Input: arr[] = {7, 10, 4, 3, 20, 15}, K = 4 
Output: 10 


*/

/*
    SOLUTION 1  : 
    [Expected Approach] Using Priority Queue(Max-Heap) – O(N * log(K)) time
     and O(K) auxiliary space:  
*/
int Solution1(vector <int > & arr , int k ){
    //create a max heap (using priority queue)
    priority_queue <int> pq ;   
    int n = arr.size() ; 
    for (int i  =  0 ; i<n ; i++){
        pq.push(arr[i]);

        if (pq.size() > k ){
            pq.pop() ; 
        }
    }
    return pq.top() ; 
}

int main() {
    vector <int> arr = {43, 91, 13, 67, 25, 82, 31, 49, 11, 58};
    int k = 4 ; 
    cout << Solution1(arr , k) << endl ;
    return 0;
}