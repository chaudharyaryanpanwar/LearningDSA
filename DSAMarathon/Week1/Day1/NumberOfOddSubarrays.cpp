#include <bits/stdc++.h>
#define long long int ll
using namespace std;
/*
Total Number of Odd Subarrays
You are given an array of integers, and your task is to find
the total number of odd subarrays. A subarray is considered "odd"
if the sum of its elements is an odd number.

A subarray is defined as any contiguous sequence of elements in the array.
The sum of a subarray is the sum of all its elements.

Write a function that computes the total number of odd subarrays in
the given array.

Input:
An integer n (1 ≤ n ≤ 10^5), the size of the array.
A list of integers arr[] of size n where each element arr[i]
(−10^5 ≤ arr[i] ≤ 10^5).
Output:
A single integer representing the total number of odd subarrays in the given array.
Example 1:
Input:

n = 4
arr = [1, 2, 3, 4]
Output:6
Explanation:
The odd subarrays are:
[1] → sum = 1 (odd)
[2, 3] → sum = 5 (odd)
[3] → sum = 3 (odd)
[1, 2, 3, 4] → sum = 10 (even) — not considered.
Thus, the total number of odd subarrays is 4.

Example 2:
Input:
n = 3
arr = [1, 1, 1]
Output:6
Explanation:

The odd subarrays are:
[1] → sum = 1 (odd)
[1] → sum = 1 (odd)
[1] → sum = 1 (odd)
[1, 1] → sum = 2 (even) — not considered.
[1, 1] → sum = 2 (even) — not considered.
[1, 1, 1] → sum = 3 (odd)
Thus, the total number of odd subarrays is 6.
*/

// ENDPOINT FIXING TECHNIQUE
int countOddSubarrays(vector<int> arr)
{
    int n = arr.size();
    int currPrefix = 0;
    int ans = 0;
    int odd = 0;
    int even = 1;
    for (int i = 0; i < n; i++)
    {
        currPrefix += arr[i];
        if (currPrefix & 1)
        {
            ans += even;
            odd++;
        }
        else
        {
            ans += odd;
            even++;
        }
    }
    return ans;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << countOddSubarrays(arr);
    fclose(stdin);
    fclose(stdout);
    return 0;
}