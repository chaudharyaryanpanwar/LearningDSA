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
Merge Intervals:
   - Description: Given a collection of intervals, merge all overlapping intervals.
   - Sample Test Case:
     Input: [[1,3],[2,6],[8,10],[15,18]]
     Output: [[1,6],[8,10],[15,18]]
     Explanation: Merging intervals [1,3] and [2,6].
*/
bool compareIntervals(const vector<int> &a , const vector<int> &b ){
    return a[0]<b[0];
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin() , intervals.end() , compareIntervals);
    vector<vector<int>> result;
    result.push_back(intervals[0]);

    for (int i =1  ; i<intervals.size() ; i++){
        vector <int> &lastMerged  = result.back() ;
        if (lastMerged[1] >= intervals[i][0]){
            lastMerged[1] = max(lastMerged[1] , intervals[i][1]);
        } else {
            result.push_back(intervals[i]);
        }
    }
    return result;
}
int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10},{9 , 12} , {15, 18}};
   
    // Merge intervals
    vector<vector<int>> mergedIntervals = merge(intervals);


    // Print the result
    cout << "Merged Intervals: " << endl;
    for (const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}