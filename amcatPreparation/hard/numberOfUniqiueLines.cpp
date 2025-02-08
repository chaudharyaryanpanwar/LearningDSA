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
Problem Statement:

In a certain town, there are n students, each living in houses located at specific coordinates.
The coordinates of the houses are represented as pairs of integers (x, y).
Before listing the coordinates, you will first input the number of coordinates
for each student's house. Additionally, there is a teacher who also has a house
located at a specific coordinate. Your task is to determine how many unique straight lines
can be formed from the teacher's house to each of the students' houses.

Input:

The first line contains an integer n (1 ≤ n ≤ 1000), the number of students.
The second line contains an integer m (1 ≤ m ≤ 1000), the number of coordinates for each
student's house.
The next n lines each contain m pairs of integers x_i and y_i (−10^4 ≤ x_i, y_i ≤ 10^4),
representing the coordinates of the students' houses.
The last line contains two integers x_t and y_t (−10^4 ≤ x_t, y_t ≤ 10^4),
representing the coordinates of the teacher's house.
Output:

Output a single integer representing the number of unique lines that can be formed
from the teacher's house to the students' houses.
Example:

Input:

3
2
1 2
2 3
1 3
0 0
Output:

2
Explanation:
In this example, the teacher's house is at (0, 0).
The students' houses are at (1, 2), (2, 3), and (1, 3).
The unique lines formed are:

From (0, 0) to (1, 2)
From (0, 0) to (2, 3)
The line from (0, 0) to (1, 3) is not unique because it shares the same slope
as the line from (0, 0) to (1, 2).


*/

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void normalizeSlopes(int &dx, int &dy) {
    int d = gcd(dy, dx);
    dy = dy / d;
    dx = dx / d;
}

pair<int, int> calculateSlopes(int xi, int yi, int xt, int yt) {
    int dy = yi - yt; // Corrected slope calculation
    int dx = xi - xt;

    // Normalize slopes
    normalizeSlopes(dx, dy);

    // Ensure consistent representation of slopes
    if (dx < 0) {
        dy = -dy;
        dx = -dx;
    } else if (dx == 0) {
        dy = (dy > 0) ? 1 : -1; // Vertical lines
    }
    return {dx, dy};
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> students; // Initialize empty vector

    for (int i = 0; i < n; i++) {
        // for (int j = 0; j < m; j++) {
            int xi, yi;
            cin >> xi >> yi;
            students.push_back({xi, yi}); // Store coordinates directly
        // }
    }

    int xt, yt; 
    cin >> xt >> yt; 

    set<pair<int, int>> uniqueSlopes;
    for (const auto &it : students) { // Use const reference to avoid copying
        auto slope = calculateSlopes(it.first, it.second, xt, yt);
        uniqueSlopes.insert(slope);
    }

    cout << "Total unique lines: " << uniqueSlopes.size() << endl; 
    return 0;
}