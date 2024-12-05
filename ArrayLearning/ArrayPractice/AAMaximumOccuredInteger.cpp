#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
Given n integer ranges, the task is to return the maximum occurring integer in the given ranges. 
If more than one such integer exists, return the smallest one.
The ranges are in two arrays l[] and r[].  
l[i] consists of the starting point of the range and r[i] 
consists of the corresponding endpoint of the range & a maxx which is the maximum value of r[].

For example, consider the following ranges.
l[] = {2, 1, 3}, r[] = {5, 3, 9}
Ranges represented by the above arrays are.
[2, 5] = {2, 3, 4, 5}
[1, 3] = {1, 2, 3}
[3, 9] = {3, 4, 5, 6, 7, 8, 9}
The maximum occurred integer in these ranges is 3.

Examples :

Input: n = 4, l[] = {1,4,3,1}, r[] = {15,8,5,4}, maxx = 15
Output: 4
Explanation: The given ranges are [1, 15] [4, 8] [3, 5] [1, 4]. 
    The smallest number that is most common or appears most times in the ranges is 4.
Input: n = 5, l[] = {1,5,9,13,21}, r[] = {15,8,12,20,30}, maxx = 30
Output: 5
Explanation: The given ranges are [1, 15] [5, 8] [9, 12] [13, 20] [21, 30]. 
    The smallest number that is most common or appears most times in the ranges is 5.
Expected Time Complexity: O(n+maxx).
Expected Auxiliary Space: O(maxx), maxx is maximum element in r[]
*/

//BRUTE FORCE 
int findMaximumOccured1(vector <int> &l , vector <int>& r , int n , int max){
                                            // T : O(N * max) , S: O(1)
    int i , j , count , element  = -1 ; 
    int maxVal = INT_MIN ; 
    for (int i= 0 ; i<=max ; i++){
        count  = 0 ; 
        for (int j = 0 ; j<n ; j++){
            if (l[j] <= i && i <= r[j]){
                count++ ; 
            }
        }
        if (count > maxVal){
            maxVal = count ; 
            element = i ; 
        }
    }
    return element ; 
}

//BEST APPROACH 
int findMaximumOccured(vector <int> & l , vector <int> & r , int n , int max){
                    // T : O(N+max) , S: O(max)
    vector <int> arr(max+2 , 0);
    for (int i = 0 ; i<n ; i++){
        arr[l[i]]++; //increment at range start 
        arr[r[i]+1]--; //decrement after range end 
    }
    int maxFreq = arr[0];
    int result = 0 ; 
    for (int i =0  ; i<= max ; i++){
        //usin prefix sum 
        arr[i]+= arr[i-1];

        if (arr[i] > maxFreq || (arr[i]== maxFreq && i<result)){
            maxFreq = arr[i] ;
            result = i ;
        }
    }
    return result ; 
}
int main() {
    vector <int> l = {2, 1, 3} ; 
    vector <int > r = { 5 , 3, 9};
    int n = 3 ; 
    int max = 9 ;
    cout << findMaximumOccured1(l , r , n , max) << endl ;
    cout << findMaximumOccured(l , r , n , max) ;
    return 0;
}