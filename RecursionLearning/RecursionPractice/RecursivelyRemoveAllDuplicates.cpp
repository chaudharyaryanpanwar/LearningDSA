#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

/*
Given a string S, the task is to remove all its adjacent duplicate characters recursively.

Examples: 

Input: S = “geeksforgeek”
Output: “gksforgk”
Explanation: g(ee)ksforg(ee)k -> gksforgk


Input: S = “abccbccba”
Output: ““
Explanation: ab(cc)b(cc)ba->abbba->a(bbb)a->aa->(aa)->”” (empty string
*/
//BEST APPROACH 
void removeDuplicates(string &str , int n){
    int len = str.length();

    //index to store the result string
    int k =0 ; 

    //iterate over the string to remove the adjacent
    for (int i = 0 ; i<n ; i++){
        //check the current character same as the next one
        if ( i< n-1 && str[i] == str[i+1]){
            //skip all the adjacent duplicates
            while (i <n-1 && str[i] ==str[i+1]){
                i++ ; 
            }
        } else {
            //if not duplicate store the character
            str[k++] = str[i];
        }
    }
    //remove the remaining character from the string
    str.resize(k);

    //if any adjacent duplicates were removed , 
    //recursively check for more
    if ( k != n){
        removeDuplicates(str , k );
    }
}

//NAIVE APPROACH : Require additional space result string
string NaiveRemoveDuplicates(string s ){
    if (s.length() <= 1)return s; 
    int n = s.length() ; 

    string result ; 

    for (int i=0 ; i<n ; i++){
        if (s[i]==s[i+1] && i<n-1){
            while (i<n-1 && s[i]==s[i+1])
            {
                i++;
            }
        } else {
            result += s[i];
        }
    }
    if (s.length() == result.length())return result ; 
    else return NaiveRemoveDuplicates(result);
}
int main() {
    string s = "geeksforgeeks";
    string str = "abccbccbad";
    removeDuplicates(str , str.length() );
    cout << str <<endl ; 
    cout << NaiveRemoveDuplicates(s);
    return 0;
}