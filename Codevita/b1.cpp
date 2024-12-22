#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
void backtrackRemovals(string mainString , int removed , vector <string> &substrings , int & maxRemovals){
    int n = substrings.size() ; 
    if(removed > maxRemovals){
        maxRemovals = removed;
    }
    for (int i =0  ; i<n ; i++){
        int pos = mainString.find(substrings[i]);
        if (pos == -1){
            continue ; 
        } else {
            string newString = mainString.substr(0,pos) + mainString.substr(pos+substrings[i].length());
            backtrackRemovals(newString , removed+1 , substrings , maxRemovals);
        }
    }
}
int findMaxSubstringRemovals(string mainString , vector <string> & substrings){
    int maxRemovals = 0 ; 
    backtrackRemovals(mainString , 0 , substrings , maxRemovals);
    return maxRemovals;
}
int main() {
    int n ; 
    cin >> n ; 
    vector <string> substrings(n) ;
    for (int i = 0 ; i<n ; i++){
        cin >> substrings[i];
    }
    string mainString ;
    cin >> mainString ;
    cout << findMaxSubstringRemovals(mainString , substrings) ;
    return 0;
}