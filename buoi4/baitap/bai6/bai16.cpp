#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Point {
    int x, y, steps;
};

bool isValid(int x, int y, int M, int N, const vector<vector<int>>& A, vector<vector<bool>>& visited) {
    return (x >= 0 && x < M && y >= 0 && y < N && !visited[x][y]);
}

int minSteps(int M, int N, const vector<vector<int>>& A) {
    vector<vector<bool>> visited(M, vector<bool>(N, false));
    queue<Point> q;
    q.push({0, 0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        if (current.x == M - 1 && current.y == N - 1) {
            return current.steps;
        }

        int jump = A[current.x][current.y];

        // Di chuyển đến vị trí A[i][j + A[i][j]]
        int newY = current.y + jump;
        if (isValid(current.x, newY, M, N, A, visited)) {
            visited[current.x][newY] = true;
            q.push({current.x, newY, current.steps + 1});
        }

        // Di chuyển đến vị trí A[i + A[i][j]][j]
        int newX = current.x + jump;
        if (isValid(newX, current.y, M, N, A, visited)) {
            visited[newX][current.y] = true;
            q.push({newX, current.y, current.steps + 1});
        }
    }

    return -1; // Không tìm thấy đường đi
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int M, N;
        cin >> M >> N;
        vector<vector<int>> A(M, vector<int>(N));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> A[i][j];
            }
        }

        cout << minSteps(M, N, A) << endl;
    }

    return 0;
}