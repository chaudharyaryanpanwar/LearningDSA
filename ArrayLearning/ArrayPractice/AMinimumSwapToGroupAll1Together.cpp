#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
Given a binary circular array nums, return the minimum number of swaps 
required to group all 1's present in the array together at any location.

Example 1:

Input: nums = [0,1,0,1,1,0,0]
Output: 1
Explanation: Here are a few of the ways to group all the 1's together:
[0,0,1,1,1,0,0] using 1 swap.
[0,1,1,1,0,0,0] using 1 swap.
[1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
There is no way to group all 1's together with 0 swaps.
Thus, the minimum number of swaps required is 1.
Example 2:

Input: nums = [0,1,1,1,0,0,1,1,0]
Output: 2
Explanation: Here are a few of the ways to group all the 1's together:
[1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the array).
[1,1,1,1,1,0,0,0,0] using 2 swaps.
There is no way to group all 1's together with 0 or 1 swaps.
Thus, the minimum number of swaps required is 2.
Example 3:

Input: nums = [1,1,0,0,1]
Output: 0
Explanation: All the 1's are already grouped together due to the circular property of the array.
Thus, the minimum number of swaps required is 0.
*/
int minSwapsRequired(vector <int> & arr){
    int n = arr.size() ; 
    int count = 0; 
    for (int i=0 ; i<n ; i++){
        if (arr[i] == 1){
            count++;
        }
    }

    int i= 0 ; 
    int j = count-1 ; 
    int swaps = 0 ;
    int minSwap = INT_MAX; 
    while (i <= j){
        if (arr[i]==0)swaps++; 
        i++;
    }
    i =1 ; 
    j++;
    while(j<n){
        if (arr[j]==0)swaps++ ;
        if (arr[i-1]==0)swaps--;
        minSwap = min(minSwap , swaps);
        j++;
        i++;
    }
    return minSwap  ;
}
int main() {
    vector <int> arr = {0,1,1,1,0,0,1,1,0};
    cout << minSwapsRequired(arr);
    return 0;
}