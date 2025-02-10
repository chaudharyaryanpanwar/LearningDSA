#include <bits/stdc++.h>
#define long long int ll
using namespace std;
/*
MAXIMUM SUBARRAY SUM without using kadanes algorithm
Input: arr = [-2, -3, 4, -1, -2, 1, 5, -3]
Output: [4, -1, -2, 1, 5] , 7
Explanation:
In the above input, the maximum contiguous subarray sum is 7 and the elements of the subarray are [4, -1, -2, 1, 5]

Input: arr = [-2, -5, 6, -2, -3, 1, 5, -6]
Output: [6, -2, -3, 1, 5] , 7
Explanation:
In the above input, the maximum contiguous subarray sum is 7 and the elements
of the subarray are [6, -2, -3, 1, 5]
*/

// using prefix sum  basic approach before optimization

// ENDPOINT FIXING TECHNIQUE
int maxSubArraySum(const vector<int> &arr)
{
    int n = arr.size();
    int currPrefix = 0;
    int minPrefix = 0;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currPrefix += arr[i];
        minPrefix = min(minPrefix, currPrefix);
        ans = max(ans, currPrefix - minPrefix);
    }
    return ans;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maxSubArraySum(arr);
    fclose(stdin);
    fclose(stdout);
    return 0;
}