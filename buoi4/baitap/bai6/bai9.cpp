#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Point {
    int x, y, steps;
};

bool isValid(int x, int y, int N, const vector<vector<char>>& board, vector<vector<bool>>& visited) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == '.' && !visited[x][y]);
}

int minSteps(int N, const vector<vector<char>>& board, int a, int b, int c, int d) {
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<Point> q;
    q.push({a, b, 0});
    visited[a][b] = true;

    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        if (current.x == c && current.y == d) {
            return current.steps;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = current.x + directions[i][0];
            int ny = current.y + directions[i][1];

            while (isValid(nx, ny, N, board, visited)) {
                visited[nx][ny] = true;
                q.push({nx, ny, current.steps + 1});
                nx += directions[i][0];
                ny += directions[i][1];
            }
        }
    }

    return -1; // Không tìm thấy đường đi
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<vector<char>> board(N, vector<char>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> board[i][j];
            }
        }

        int a, b, c, d;
        cin >> a >> b >> c >> d;

        cout << minSteps(N, board, a, b, c, d) << endl;
    }

    return 0;
}