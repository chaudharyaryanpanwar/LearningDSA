#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
Given a sorted array of positive integers. 
Your task is to rearrange the array elements alternatively i.e first element should be max value, 
second should be min value, third should be second max, fourth should be second min and so on.
Note: Modify the original array itself. Do it without using any extra space. You do not have to return anything.

Example 1:

Input:
n = 6
arr[] = {1,2,3,4,5,6}
Output: 6 1 5 2 4 3
Explanation: Max element = 6, min = 1, 
second max = 5, second min = 2, and 
so on... Modified array is : 6 1 5 2 4 3.
Example 2:

Input:
n = 11
arr[]={10,20,30,40,50,60,70,80,90,100,110}
Output:110 10 100 20 90 30 80 40 70 50 60
Explanation: Max element = 110, min = 10, 
second max = 100, second min = 20, and 
so on... Modified array is : 
110 10 100 20 90 30 80 40 70 50 60.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
*/
void rearrangeArrayItself(vector <int > &arr ){
    int n = arr.size() ; 
    int maxVal = arr[n-1] +  1 ; 
    int minIndex = 0  ; 
    int maxIndex = n-1 ; 
    for (int i= 0 ; i<n ; i++){
        if ( i%2 == 0 ){
            arr[i] = arr[i] + (arr[maxIndex]%maxVal)*maxVal;
            maxIndex -- ; 
        } else {
            arr[i] = arr[i] +  (arr[minIndex]%maxVal)*maxVal ; 
            minIndex++;
        }
        cout << arr[i] << " ";
    }
    for(int i = 0 ; i<n; i++)arr[i] /= maxVal ; 
    cout << endl ; 
    for (int i : arr)cout << i<<" ";
        
}

void bruteforce(vector <int> &arr){
    int n =arr.size() ; 
    vector <int> ans(n);
    int l =0 ; 
    int r = n-1 ;
    int i =0 ; 
    while (l<r){
        ans[i++] = arr[r--];
        ans[i++] = arr[l++];
    }
    for (int i : ans)cout << i <<" ";
    cout << endl ; 
}
int main() {
    vector <int> arr = {1,2,3,4,5,6} ; // 110 20 100 40 90 60 70 80 50 30 10 -> 110 10 100 20 90 40 70 60 
    // bruteforce(arr);
    rearrangeArrayItself(arr);
    return 0;
}