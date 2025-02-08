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
A satellite transmits an array of integers (of size n) 
to a ground station. The ground station responds with an array of 
integers (of size m, where m < n) that are selected from the original array 
sent by the satellite. The integers returned by the ground station should 
be those with the highest number of set bits. Given the value of m, 
output an array containing the m integers with the most set bits from the satellite's array.
*/
int countSetBits(int num){
    int count =0 ; 
    while (num){
        num = num & (num -1);
        count++;
    }
    return count ; 
}
bool compareNum(int a , int b){
    int ca = countSetBits(a) ; 
    int cb = countSetBits(b) ; 
    if (ca == cb){
        return a > b ; 
    } 
    return ca > cb;
}
void findMostSetBits(vector<int>& nums, int m) {
    int n= nums.size() ; 
    sort(nums.begin() , nums.end() , compareNum);
    for (int i = 0 ; i < m ; i++){
        cout << nums[i] << " " ;
    }
    return ; 
}
int main() {
    vector <int> sattelliteRequest = { 5 , 9 , 7 , 8 , 16 , 2 , 3 };
    int m = 3 ;
    findMostSetBits(sattelliteRequest , m);
    return 0;
}