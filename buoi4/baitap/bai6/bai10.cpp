#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Point {
    int x, y, days;
};

bool isValid(int x, int y, int R, int C, const vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    return (x >= 0 && x < R && y >= 0 && y < C && grid[x][y] == 1 && !visited[x][y]);
}

int minDaysToGerminate(int R, int C, vector<vector<int>>& grid) {
    queue<Point> q;
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    int totalSeeds = 0;
    int germinatedSeeds = 0;

    // Đẩy tất cả các cây non vào hàng đợi và đánh dấu chúng là đã thăm
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == 2) {
                q.push({i, j, 0});
                visited[i][j] = true;
            }
            if (grid[i][j] == 1) {
                totalSeeds++;
            }
        }
    }

    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int days = 0;

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = current.x + directions[i][0];
            int ny = current.y + directions[i][1];

            if (isValid(nx, ny, R, C, grid, visited)) {
                visited[nx][ny] = true;
                q.push({nx, ny, current.days + 1});
                germinatedSeeds++;
                days = current.days + 1;
            }
        }
    }

    return (germinatedSeeds == totalSeeds) ? days : -1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> grid(R, vector<int>(C));
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                cin >> grid[i][j];
            }
        }

        cout << minDaysToGerminate(R, C, grid) << endl;
    }

    return 0;
}