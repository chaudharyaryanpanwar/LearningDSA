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
Group Anagrams:
   - Description: Given an array of strings, group the anagrams together.
   - Sample Test Case:
     Input: ["eat", "tea", "tan", "ate", "nat", "bat"]
     Output: [["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]
     Explanation: Grouping the anagrams together.
*/
vector <vector <string>> groupAnagrams(vector <string> & strs){
    unordered_map <string  , vector <string>> mp ; 

    for (const string &str : strs){
        string key = str ; 
        sort(key.begin() , key.end());
        mp[key].push_back(str) ; 
    }

    vector <vector <string>>result ; 
    for (auto pair : mp){
        result.push_back(pair.second) ;
    }
    return result ; 
}

int main() {
    vector <string> strs = {"eat", "tea", "tan", "ate", "nat", "bat" };
    vector <vector <string>> result = groupAnagrams(strs) ;
    for (const vector <string> &vec : result){
        for (const string &str : vec){
            cout << str << " " ;
        }
        cout << endl ;
    }

    return 0;
}