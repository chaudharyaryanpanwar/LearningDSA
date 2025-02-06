#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>

using namespace std;
/*
Given an unsorted array arr of nonnegative integers and an integer sum, find a continuous subarray which adds to a given sum. There may be more than one subarrays with sum as the given sum, print first such subarray. 
Examples : 

Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
Output: Sum found between indexes 2 and 4
Sum of elements between indices 2 and 4 is 20 + 3 + 10 = 33
 

Input: arr[] = {1, 4, 0, 0, 3, 10, 5}, sum = 7
Output: Sum found between indexes 1 and 4
Sum of elements between indices 1 and 4 is 4 + 0 + 0 + 3 = 7

 
Input: arr[] = {1, 4}, sum = 0
Output: No subarray found
There is no subarray with 0 sum
*/
vector <int> subarray(vector <int> & arr , int target){
    int n = arr.size() ; 
    int sum =0 ; 
    int l =0 , r= 0 ; 
    while(r != n){
        sum += arr[r];
       
        while (sum > target && l < r ){
            sum -= arr[l];
            l++;
        }
        
        if (sum == target){
            return {l , r};
        }

        r++;
    }
    return {-1,-1};
}
int main() {
    vector <int> arr = {1, 4, 20, 3, 10, 5};
    int target = 33;
    vector <int> ans = subarray(arr , target);
    if (ans[0] == -1){
        cout << "No subarray found" << endl;
        }
    else{
        cout << "Sum found between indexes " << ans[0] << " and " << ans[1] << endl;
    }
    return 0;
}