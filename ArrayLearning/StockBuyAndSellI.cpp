#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
Input: arr[] = {100, 180, 260, 310, 40, 535, 695}
Output: 865
Explanation: Buy the stock on day 0 and sell it on day 3 => 310 – 100 = 210
                       Buy the stock on day 4 and sell it on day 6 => 695 – 40 = 655
                       Maximum Profit  = 210 + 655 = 865
Input: arr[] = {4, 2, 2, 2, 4}
Output: 2
Explanation: Buy the stock on day 1 and sell it on day 4 => 4 – 2 = 2
                       Maximum Profit  = 2
*/
int maxProfit(vector <int> &arr){ // T : N , S : 1

    int n = arr.size() ; 
    int profit  = 0 ; 
    int sp = arr[n-1];

    for (int i = n - 2 ; i>= 0 ; i--){
        if (arr[i] < sp){
            profit += sp - arr[i];
        } 
        sp = arr[i] ; 
    }
    return profit ; 
}

//VALLEY PEAK APPROACH 
int maxProfitII(vector <int> &arr){ // T : N
    int n = arr.size() ; 
    int profit = 0 ; 

    for (int i = 1 ; i<n ; i++){
        if (arr[i]>arr[i-1]){
            profit += arr[i] - arr[i-1];
        }
    }
    return profit ; 
}

int main() {
    vector <int> arr = {100, 80, 260, 780, 40, 40, 40};
    cout << maxProfit(arr) << endl;
    cout << maxProfitII(arr);
    return 0;
}