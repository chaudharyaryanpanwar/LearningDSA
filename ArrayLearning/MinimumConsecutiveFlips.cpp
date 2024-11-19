#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
Given a binary array, we need to convert this array into an array that either contains all 1s or all 0s. 
We need to do it using the minimum number of group flips. 
 
Examples : 

Input : arr[] = {1, 1, 0, 0, 0, 1}
Output :  From 2 to 4
Explanation : We have two choices, we make all 0s or do all 1s.  We need to do two group flips to make all elements 0 and one group flip to make all elements 1.  Since making all elements 1 takes the least group flips, we do this.
 

Input : arr[] = {1, 0, 0, 0, 1, 0, 0, 1, 0, 1}
Output :  
From 1 to 3
From 5 to 6
From 8 to 8
 

Input : arr[] = {0, 0, 0}
Output :  
Explanation : Output is empty, we need not to make any change
 

Input : arr[] = {1, 1, 1}
Output :  
Explanation : Output is empty, we need not to make any change
 

Input : arr[] = {0, 1}
Output :   
From 0 to 0  
OR
From 1 to 1
Explanation :  Here number of flips are same either we make all elements as 1 or all elements as 0.
 
*/
int NaiveSolution(vector <int> &arr){ // T : N , S: 1
    int n = arr.size() ; 
    int count1 =0 ; 
    
    for (int i =0 ; i<n ; i++){
        if (arr[i]==0){
            while(arr[i]==0)i++;
            count1++;
        }
    }
    // cout << count1 << endl ; 

    int count2 =0 ; 
    for (int i =0 ; i<n ; i++){
        if (arr[i]==1){
            while (arr[i]==1)i++;
            count2++;
        }
    }
    return min(count1 , count2); 
}

int EfficientSolutoin(vector <int> &arr){ // T : N , S : 1
    int n = arr.size() ; 
    int count1 =0 ; 
    int count2 =0 ; 
    for (int i =0 ; i<n ; i++){
        if (arr[i]!=arr[i-1]){
            if (arr[i]==0){
                count1++;
            } else {
                count2++;
            }
        }
    }
    cout << "Count 1 : " << count1 << endl; 
    cout << "Count 2 : " << count2 << endl ; 
    return min(count1 , count2);
}

int main() {
    vector <int> arr = {1, 0, 0, 0, 1, 0, 0, 1, 0, 1};
    
    cout << NaiveSolution(arr);
    EfficientSolutoin(arr);
    return 0;
}