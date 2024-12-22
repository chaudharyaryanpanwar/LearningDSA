#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;
/*

*/
int main ()
int N, M;
vector<vector<int>> grid;
unordered_map<int, vector<pair<int, int>>> blockPositions; 
unordered_set<string> removedBlocks;

const int dx[] = {0, 0, 1, -1}; 
const int dy[] = {1, -1, 0, 0};

void findBlocks() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int colorCode = grid[i][j];
            blockPositions[colorCode].push_back({i, j}); 
        }
    }
}

void applyGravity() {
    for (int j = 0; j < M; j++) {
        for (int i = N - 2; i >= 0; i--) {
            if (grid[i][j] != 0 && grid[i + 1][j] == 0) {
                grid[i + 1][j] = grid[i][j];
                grid[i][j] = 0;
            }
        }
    }
}
void removeBlock(int x, int y) {
    string pos = to_string(x) + "," + to_string(y);
    if (removedBlocks.count(pos)) return;
    removedBlocks.insert(pos);
    grid[x][y] = 0;
    applyGravity();
}
int removeBlocks(int targetColorCode) {
    int removalCount = 0;
    queue<pair<int, int>> toRemove;
    for (auto& pos : blockPositions[targetColorCode]) {
        toRemove.push(pos);
    }
    while (!toRemove.empty()) {
        pair<int, int> blockPos = toRemove.front();
        toRemove.pop();
        int x = blockPos.first;
        int y = blockPos.second;

        removeBlock(x, y);
        removalCount++;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M && grid[nx][ny] == grid[x][y]) {
                string pos = to_string(nx) + "," + to_string(ny);
                if (!removedBlocks.count(pos)) {
                    toRemove.push({nx, ny});
                }
            }
        }
    }
    return removalCount;
}

int main() {
    cin >> N >> M;
    grid.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }
    int targetColorCode;
    cin >> targetColorCode;
    findBlocks();
    int result = removeBlocks(targetColorCode) + 1;
    cout << result ;
    return 0;
}
