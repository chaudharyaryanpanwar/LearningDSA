#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

/*
*/

bool isPalindrome(const string& s , int left , int right){
    while (left < right){
        if (s[left]!=s[right])return false ; 
        left++;
        right-- ; 
    }
    return true ; 
}

//revursive function to find the lognest palindromic substring
int longestPalindromeUtil(const string &s  , int left , int right){
    if (left >= right)return 0 ; //base case 

    // check if the current string is palindrome
    if (isPalindrome(s , left , right)){
        return right - left +1  ; //return length of the strign
    }
    //if not palindrome then try to find the longest palindromic substring
    //by reducing the range
    int len1 = longestPalindromeUtil(s , left +1 , right);
    int len2 = longestPalindromeUtil(s , left , right -1);

    return max(len1 , len2); //return the maximum length
}

int longestPalindromicSubstring(const string &s ){
    if (s.empty())return 0 ; 
    return longestPalindromeUtil(s , 0 , s.length() -1 );
}

int main() {
    string s = "banana";
    cout << longestPalindromicSubstring(s) << endl;
    return 0;
}