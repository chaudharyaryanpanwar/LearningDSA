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
Given a sorted and rotated array arr[] of distinct elements, 
the task is to find the index of a target key. 
Return -1 if the key is not found.

Examples :
Input: arr[] = [5, 6, 7, 8, 9, 10, 1, 2, 3], key = 3
Output: 8
Explanation: 3 is found at index 8.
Input: arr[] = [3, 5, 1, 2], key = 6
Output: -1
Explanation: There is no element that has value 6.
Input: arr[] = [33, 42, 72, 99], key = 42
Output: 1
Explanation: 42 is found at index 1.
*/
int searchInSortedRotated(vector <int> & arr , int target){
    int n = arr.size() ; 
    int low =  0 ; 
    int high = n - 1 ; 
    while ( low <= high ){
        int mid = low + (high - low)/2 ; 
        if (arr[mid]== target){
            return mid ; 
        }
        else if (arr[low] <= arr[mid]){
            if (target >= arr[low] && arr[mid] > target ){
                high = mid -1 ; 
            } else {
                low = mid + 1 ;
            }
        } else {
            if (target > arr[mid] && target <= arr[high]){
                low = mid + 1 ; 
            } else {
                high = mid -1 ; 
            }
        }
    }
    return -1 ; 
}
int main() {
    vector <int> arr = {5, 6, 7, 8, 9, 10, 1, 2, 3} ; 
    int key = 3 ;
    cout << searchInSortedRotated(arr , key) ; 
    return 0;
}