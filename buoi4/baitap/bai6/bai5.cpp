#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int minOperations(int S, int T) {
    if (S >= T) {
        return S - T;
    }

    queue<pair<int, int>> q;
    unordered_set<int> visited;
    q.push({S, 0});
    visited.insert(S);

    while (!q.empty()) {
        int current = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (current == T) {
            return steps;
        }

        if (current * 2 == T || current - 1 == T) {
            return steps + 1;
        }

        if (current * 2 < T * 2 && visited.find(current * 2) == visited.end()) {
            q.push({current * 2, steps + 1});
            visited.insert(current * 2);
        }

        if (current - 1 > 0 && visited.find(current - 1) == visited.end()) {
            q.push({current - 1, steps + 1});
            visited.insert(current - 1);
        }
    }

    return -1; // Không tìm thấy đường đi
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int S, T;
        cin >> S >> T;
        cout << minOperations(S, T) << endl;
    }

    return 0;
}