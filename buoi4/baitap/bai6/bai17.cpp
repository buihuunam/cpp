#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

// Các hướng di chuyển của quân mã
int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

// Hàm chuyển đổi tọa độ từ ký tự sang số nguyên
pair<int, int> toCoords(string pos) {
    return {pos[0] - 'a', pos[1] - '1'};
}

// Thuật toán BFS tìm số bước ít nhất
int bfs(string start, string end) {
    if (start == end) return 0;
    
    queue<pair<int, int>> q;
    unordered_map<int, unordered_map<int, int>> dist;
    
    auto [sx, sy] = toCoords(start);
    auto [ex, ey] = toCoords(end);
    
    q.push({sx, sy});
    dist[sx][sy] = 0;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && dist.find(nx) == dist.end() || dist[nx].find(ny) == dist[nx].end()) {
                dist[nx][ny] = dist[x][y] + 1;
                if (nx == ex && ny == ey) return dist[nx][ny];
                q.push({nx, ny});
            }
        }
    }
    return -1; // Không thể xảy ra
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string start, end;
        cin >> start >> end;
        cout << bfs(start, end) << endl;
    }
    return 0;
}
