#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*

6

hd el llo wor ell lds

helloworlds

Output

4

Explanation

Given main string is - helloworlds

Remove llo, the string becomes heworlds

Remove wor, the string becomes helds

Remove el, the string becomes hds

Remove hd, the string becomes s. One cannot remove anything further.

Hence the maximum number of substrings we can remove is 4, print 4 as output.

Example 2

Input

7

ggc rm oo le glh oog ec

googlechrome

Output

3

Explanation

Given main string is - googlechrome

Remove oo, the string becomes gglechrome

Remove le, the string becomes ggchrome

Remove ggc, the string becomes hrome. One cannot remove anything further.

Second possibility can also be - removing ec,glh,oo resulting in grome, further reduction is impossible. In this case also only 3 substrings have been removed.

Hence the maximum number of substrings we can remove is 3, hence print 3 as output.
*/


void backtrackSubstrings(string current, int removed, vector<string>& substrings, int& maxRemoved) ;
int maxSubstringsRemoved(string mainString, vector<string>& substrings) {
    int maxRemoved = 0;
    backtrackSubstrings(mainString, 0, substrings, maxRemoved);
    return maxRemoved;
}

void backtrackSubstrings(string current, int removed, vector<string>& substrings, int& maxRemoved) {
    maxRemoved = max(maxRemoved, removed);
    
    for (string& sub : substrings) {
        int pos = current.find(sub);
        if (pos != -1) {
            string next = current.substr(0, pos) + current.substr(pos + sub.length());
            backtrackSubstrings(next, removed + 1, substrings, maxRemoved);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> substrings(n);
    for (int i = 0; i < n; i++) {
        cin >> substrings[i];
    }
    string mainString;
    cin >> mainString;
    int result = maxSubstringsRemoved(mainString, substrings);
    cout << result << endl;
    
    return 0;
}