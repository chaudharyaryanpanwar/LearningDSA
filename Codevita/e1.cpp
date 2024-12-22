#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <climits>
using namespace std;
/*

*/
bool comparatorFunction(pair <int , int > p1 , pair <int , int > p2){
    if(p1.first == p2.first){
        return p1.second > p2.second;
    } else {
        return p1.first > p2.first ; 
    }
}
bool pointInPolygon(double px, double py, const vector<pair<int, int>>& polygon) {
    int numVertices = polygon.size();
    bool isInside = false;
    int j = numVertices - 1;

    for (int i = 0; i < numVertices; i++) {
        int xi = polygon[i].first, yi = polygon[i].second;
        int xj = polygon[j].first, yj = polygon[j].second;

        if (((yi > py) != (yj > py)) && (px < xi + (xj - xi) * (py - yi) / (yj - yi))) {
            isInside = !isInside;
        }
        j = i;
    }
    return isInside;
}

int main() {
    int numCoords;
    cin >> numCoords;
    vector<pair<int, int>> points(numCoords);
    for (int i = 0; i < numCoords; i++) {
        cin >> points[i].first >> points[i].second;
    }
    int brushSize;
    cin >> brushSize;
    int offsetX = INT_MAX, offsetY = INT_MAX;
    for (const auto& point : points) {
        offsetX = min(offsetX, point.first);
        offsetY = min(offsetY, point.second);
    }
    vector<pair<int, int>> normalizedPoints;
    for (const auto& point : points) {
        normalizedPoints.push_back({point.first - offsetX, point.second - offsetY});
    }
    int maxXCoord = INT_MIN, maxYCoord = INT_MIN;
    for (const auto& point : normalizedPoints) {
        maxXCoord = max(maxXCoord, point.first);
        maxYCoord = max(maxYCoord, point.second);
    }

    int gridWidth = maxXCoord + 1;
    int gridHeight = maxYCoord + 1;
    vector<vector<int>> gridMatrix(gridWidth, vector<int>(gridHeight, 0));
    for (int x = 0; x < gridWidth; x++) {
        for (int y = 0; y < gridHeight; y++) {
            if (pointInPolygon(x + 0.5, y + 0.5, normalizedPoints)) {
                gridMatrix[x][y] = 1;
            }
        }
    }
    set<string> uncoveredCells;
    for (int x = 0; x < gridWidth; x++) {
        for (int y = 0; y < gridHeight; y++) {
            if (gridMatrix[x][y] == 1) {
                uncoveredCells.insert(to_string(x) + "," + to_string(y));
            }
        }
    }
    vector<set<string>> potentialBrushPositions;
    vector<pair<int, int>> brushPositions;
    for (int startX = 0; startX <= gridWidth - brushSize; startX++) {
        for (int startY = 0; startY <= gridHeight - brushSize; startY++) {
            set<string> coveredCells;
            for (int dx = 0; dx < brushSize; dx++) {
                for (int dy = 0; dy < brushSize; dy++) {
                    if (gridMatrix[startX + dx][startY + dy] == 1) {
                        coveredCells.insert(to_string(startX + dx) + "," + to_string(startY + dy));
                    }
                }
            }
            if (!coveredCells.empty()) {
                potentialBrushPositions.push_back(coveredCells);
                brushPositions.push_back({startX, startY});
            }
        }
    }
    int totalPresses = 0;
    while (!uncoveredCells.empty()) {
        size_t maxCovered = 0;  
        set<string> newlyCovered;
        int bestPositionIdx = -1;
        for (size_t i = 0; i < potentialBrushPositions.size(); i++) {
            set<string> overlap;
            for (const auto& cell : potentialBrushPositions[i]) {
                if (uncoveredCells.find(cell) != uncoveredCells.end()) {
                    overlap.insert(cell);
                }
            }
            if (overlap.size() > maxCovered) {
                maxCovered = overlap.size();
                newlyCovered = overlap;
                bestPositionIdx = i;
            }
        }
        if (bestPositionIdx == -1) {
            break;
        }
        for (const auto& cell : newlyCovered) {
            uncoveredCells.erase(cell);
        }
        totalPresses++;
    }
    cout << totalPresses;
    return 0;
}
