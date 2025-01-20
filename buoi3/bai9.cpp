#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef pair<int, int> Position;

struct PositionHash {
    size_t operator()(const Position& pos) const {
        return hash<int>()(pos.first) ^ hash<int>()(pos.second);
    }
};

vector<Position> get_neighbors(const vector<vector<char>>& grid, Position position) {
    int x = position.first;
    int y = position.second;
    vector<Position> neighbors;
    vector<Position> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  // up, down, left, right

    for (const auto& dir : directions) {
        int new_x = x + dir.first;
        int new_y = y + dir.second;
        if (new_x >= 0 && new_x < grid.size() && new_y >= 0 && new_y < grid[0].size()) {
            if (grid[new_x][new_y] == 'O') {
                neighbors.push_back({new_x, new_y});
            }
        }
    }
    return neighbors;
}

vector<Position> dfs(const vector<vector<char>>& grid, Position start, Position goal) {
    stack<Position> s;
    s.push(start);
    unordered_set<Position, PositionHash> visited;
    unordered_map<Position, Position, PositionHash> parent;

    while (!s.empty()) {
        Position current = s.top();
        s.pop();

        if (current == goal) {
            break;
        }

        if (visited.find(current) != visited.end()) {
            continue;
        }

        visited.insert(current);

        vector<Position> neighbors = get_neighbors(grid, current);
        for (const auto& neighbor : neighbors) {
            if (visited.find(neighbor) == visited.end()) {
                s.push(neighbor);
                parent[neighbor] = current;
            }
        }
    }

    if (parent.find(goal) == parent.end() && start != goal) {
        cout << "No path found" << endl;
        return {};
    }

    vector<Position> path;
    Position current = goal;
    while (current != start) {
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    vector<vector<char>> grid = {
        {'O', 'O', 'O', 'O', 'O'},
        {'1', '1', 'O', '1', 'O'},
        {'O', 'O', 'O', '1', 'O'},
        {'O', '1', '1', '1', 'O'},
        {'O', 'O', 'O', 'O', 'O'}
    };

    Position start = {0, 0};
    Position goal = {4, 4};
    vector<Position> path = dfs(grid, start, goal);

    if (!path.empty()) {
        cout << "Path found: " << endl;
        for (const auto& pos : path) {
            cout << "(" << pos.first << ", " << pos.second << ") ";
        }
        cout << endl;
    }

    return 0;
}