#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int minOperations(int N) {
    if (N == 1) {
        return 0;
    }

    queue<pair<int, int>> q;
    unordered_set<int> visited;
    q.push({N, 0});
    visited.insert(N);

    while (!q.empty()) {
        int current = q.front().first;
        int steps = q.front().second;
        q.pop();

        // Thao tác (a): Trừ N đi 1
        if (current - 1 == 1) {
            return steps + 1;
        }
        if (visited.find(current - 1) == visited.end()) {
            q.push({current - 1, steps + 1});
            visited.insert(current - 1);
        }

        // Thao tác (b): N = max(u, v) nếu u * v = N
        for (int i = 2; i * i <= current; ++i) {
            if (current % i == 0) {
                int maxFactor = max(i, current / i);
                if (maxFactor == 1) {
                    return steps + 1;
                }
                if (visited.find(maxFactor) == visited.end()) {
                    q.push({maxFactor, steps + 1});
                    visited.insert(maxFactor);
                }
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
        cout << minOperations(N) << endl;
    }

    return 0;
}