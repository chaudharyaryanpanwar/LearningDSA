#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
Given an unsorted array arr[]. Rotate the array to the left (counter-clockwise direction) 
by d steps, where d is a positive integer. Do the mentioned change in the array in place.

Note: Consider the array as circular.

Examples :

Input: arr[] = [1, 2, 3, 4, 5], d = 2
Output: [3, 4, 5, 1, 2]
Explanation: when rotated by 2 elements, it becomes 3 4 5 1 2.
Input: arr[] = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20], d = 3
Output: [8, 10, 12, 14, 16, 18, 20, 2, 4, 6]
Explanation: when rotated by 3 elements, it becomes 8 10 12 14 16 18 20 2 4 6.
Input: arr[] = [7, 3, 9, 1], d = 9
Output: [3, 9, 1, 7]
Explanation: when we rotate 9 times, we'll get 3 9 1 7 as resultant array.
*/
void rotate(vector <int> & arr , int l , int r){
    while(l<r)swap(arr[l++] , arr[r--]);
}
void rotateByDPlaces(vector <int> & arr , int d ){
    int n = arr.size() ;  
    rotate(arr , 0 , n-1);
     d= d%n ; 
     rotate(arr , 0 , n -d -1 );
     rotate(arr , n-d , n-1);
}
int main() {
    vector <int> arr = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int d = 3 ; 
    rotateByDPlaces(arr , d);
    for (int i : arr)cout << i << " ";
    return 0;
}