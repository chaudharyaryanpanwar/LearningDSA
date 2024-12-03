#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_set>


using namespace std;
/*
You are given an integer array arr[]. 
Your task is to find the smallest positive number missing from the array.

Note: Positive number starts from 1. The array can have negative integers too.

Examples:

Input: arr[] = [2, -3, 4, 1, 1, 7]
Output: 3
Explanation: Smallest positive missing number is 3.
Input: arr[] = [5, 3, 2, 5, 1]
Output: 4
Explanation: Smallest positive missing number is 4.
Input: arr[] = [-8, 0, -1, -4, -3]
Output: 1
Explanation: Smallest positive missing number is 1.
*/

//better approach but not the best approach 
int smallestMissingNumber1(vector <int> arr){ // T: O(NlogN) , S : O(1)
    int n = arr.size();
    sort(arr.begin(), arr.end());

    for (int i = 1 ; i<n ; i++){
        int l = 0 , r = n-1 ; 
        bool found = false ; 
        while (l <= r){
            int mid = l + (r-l)/2 ; 
            if (arr[mid] == i){
                found = true ; 
                break;
            } else if (arr[mid]>i){
                r = mid-1 ;
            } else {
                l = mid + 1 ; 
            }
        }
        if (!found){
            return i; 
        }
    }

    return -1 ; 
}

//Better Approach
int smallestMissingNumber2(vector <int> & arr){ // T: O(N) , S : O(N)
    int n = arr.size() ; 
    unordered_set <int> st ; 
    for (int i =1 ; i<=n ; i++){
        st.insert(arr[i]);
    }
    int target = 0 ; 
    for (int i = 0 ; i<=n ; i++){
        if (st.find(target)==st.end()){
            return target;
        }
        target++;
    }
    return -1 ; 
}

//BEST APPROACH : CYCLE SORT
int smallestMissingNumberCycleSort(vector <int> &arr){ // T: O(N) , S : O(1)
    int n = arr.size() ; 
    for (int i = 0 ; i<n ; i++){
        while (arr[i]>=1 && arr[i]<n && arr[i]!= arr[arr[i]-1] ){
            swap(arr[i] , arr[arr[i]-1]);
        }
    }
    for (int i = 1 ; i<n ; i++){
        if (i!=arr[i-1])return i ; 
    }
    return n+1 ; 
}

//BEST ALTERNATE APPROACH : BY NEGATING ELEMENTS 
/*Idea : The idea is to first move all positive integers to the left side of the array.
Then, we iterate over this left segment and mark the occurrences of each number x by 
negating the value at index (x - 1). 
Lastly, iterate over the left segment again and find the missing number 
by searching for the first unmarked element in it.
*/
int helpingFunctionPartition(vector <int> &arr){ //partition array into +ve and -ve subarrays
    int pivotIdx = 0 ; 
    int n = arr.size();
    for (int i =0 ; i<n ; i++){
        if (arr[i]>0){
            swap(arr[i] , arr[pivotIdx]);
            pivotIdx++;
        }
        //index of the first non-positive number
    }
    cout << pivotIdx << " : pivoIndex \n"; 
    return pivotIdx ;
}
int smallestMissingNumberNegate(vector <int> &arr){ // T: O(N) ,S : O(1)    ,
    int k = helpingFunctionPartition(arr);
    for (int i = 0 ; i<k ; i++){ //traversing the +ve part of the array
        int val = abs(arr[i]); //find the absolute value 

        //if val is within the range then mark the element index val -1 to negative
        if (val -1 <k && arr[val -1] > 0){
            arr[val - 1] = - arr[val-1];
        }
    }

    //find first unmarked index
    for (int i = 0 ; i<k ; i++){
        if (arr[i]>0)return i+1 ; 
    }
    return k+1 ; 
}
int main() {
    vector <int> arr = {2, -3, 4, 1, 1, 7} ;
    vector <int> arr1 = {1, 2, 3, 4, 5};
    
    cout << smallestMissingNumber1(arr)<<endl;
    cout << smallestMissingNumber2(arr)<<endl;
    cout << smallestMissingNumberCycleSort(arr)<<endl;
    cout << smallestMissingNumberNegate(arr1);
    return 0;
}