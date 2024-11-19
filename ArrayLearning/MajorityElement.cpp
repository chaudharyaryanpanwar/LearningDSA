#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
majority element in an array A[] of size n is an element that appears more than n/2 times 
(and hence there is at most one such element). 

Objective : Find the majority element in an array
 
Examples : 

Input : {3, 3, 4, 2, 4, 4, 2, 4, 4}
Output : 4
Explanation: The frequency of 4 is 5 which is greater than the half of the size of the array size. 

Input : {3, 3, 4, 2, 4, 4, 2, 4}
Output : No Majority Element
Explanation: There is no element whose frequency is greater than the half of the size of the array size.

*/


//Moore's Voting Algorithm
int MajorityElement(vector <int> &arr){
    int n = arr.size() ; 
    int res = 0 ; 
    int count =0 ; 
    for (int i =0 ; i<n ; i++){
        if (arr[i] == arr[res]){
            count++;
        } else {
            count--; 
            if (count < 0 ){
                res = i ; 
                count =1 ; 
            }
        }
    }
    count =0 ; 
    for (int num : arr){
        if (num == arr[res])count++;
    }
    if (count<=n/2)res = -1 ; 
    return res ; 
}

int main() {
    vector <int> arr ={3, 3, 4, 2, 4, 4, 2, 4, 4} ;
    cout << MajorityElement(arr);
    return 0;
}