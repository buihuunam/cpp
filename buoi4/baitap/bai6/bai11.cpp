#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Point {
    int x, y, z, steps;
};

bool isValid(int x, int y, int z, int A, int B, int C, const vector<vector<vector<char>>>& grid, vector<vector<vector<bool>>>& visited) {
    return (x >= 0 && x < A && y >= 0 && y < B && z >= 0 && z < C && grid[x][y][z] != '#' && !visited[x][y][z]);
}

int minSteps(int A, int B, int C, const vector<vector<vector<char>>>& grid, Point start, Point end) {
    vector<vector<vector<bool>>> visited(A, vector<vector<bool>>(B, vector<bool>(C, false)));
    queue<Point> q;
    q.push(start);
    visited[start.x][start.y][start.z] = true;

    int directions[6][3] = {{0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        if (current.x == end.x && current.y == end.y && current.z == end.z) {
            return current.steps;
        }

        for (int i = 0; i < 6; ++i) {
            int nx = current.x + directions[i][0];
            int ny = current.y + directions[i][1];
            int nz = current.z + directions[i][2];

            if (isValid(nx, ny, nz, A, B, C, grid, visited)) {
                visited[nx][ny][nz] = true;
                q.push({nx, ny, nz, current.steps + 1});
            }
        }
    }

    return -1; // Không tìm thấy đường đi
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int A, B, C;
        cin >> A >> B >> C;
        vector<vector<vector<char>>> grid(A, vector<vector<char>>(B, vector<char>(C)));
        Point start, end;

        for (int i = 0; i < A; ++i) {
            for (int j = 0; j < B; ++j) {
                for (int k = 0; k < C; ++k) {
                    cin >> grid[i][j][k];
                    if (grid[i][j][k] == 'S') {
                        start = {i, j, k, 0};
                    } else if (grid[i][j][k] == 'E') {
                        end = {i, j, k, 0};
                    }
                }
            }
        }

        cout << minSteps(A, B, C, grid, start, end) << endl;
    }

    return 0;
}