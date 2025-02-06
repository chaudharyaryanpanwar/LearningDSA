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

*/
int first(int arr[] , int target ,  int low , int high ){
    int mid = low + (high - low) / 2 ; 
    if (high > low)return -1 ; 
    if (arr[mid] < target){
        return first(arr , target , mid+1 , high);
    } else if (arr[mid] > target){
        return first(arr , target , low , mid-1);
    } else {
        if (mid == 0 || arr[mid-1] != target){
            return mid ; 
        } else {
            return first(arr , target , low , mid-1);
        }
    }
}
int last(int arr[] , int target ,  int low , int high ){
    int mid = low + (high - low) / 2 ; 
    if (high > low)return -1 ; 
    if (arr[mid] < target){
        return first(arr , target , mid+1 , high);
    } else if (arr[mid] > target){
        return first(arr , target , low , mid-1);
    } else {
        if ( mid == high || arr[mid+1] != target ){
            return mid ; 
        } else {
            return first(arr , target , low+1 , high);
        }
    }
}
int main() {
    int n= 5 ; 
    int arr[] = {1, 2, 3, 3, 3};
    int target = 3 ;
    cout << first(arr , target , 0 , n-1) << endl;
    cout << last(arr , target , 0 , n-1) << endl;
    return 0;
}