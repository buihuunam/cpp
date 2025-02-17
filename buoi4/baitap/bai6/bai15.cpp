#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

// Hàm kiểm tra xem một số có phải là số nguyên tố hay không
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// Hàm tìm số bước dịch chuyển ít nhất từ S đến T
int minTransformations(int S, int T) {
    if (S == T) return 0;

    queue<pair<int, int>> q;
    unordered_set<int> visited;
    q.push({S, 0});
    visited.insert(S);

    while (!q.empty()) {
        int current = q.front().first;
        int steps = q.front().second;
        q.pop();

        string currentStr = to_string(current);
        for (int i = 0; i < 4; ++i) {
            char originalDigit = currentStr[i];
            for (char digit = '0'; digit <= '9'; ++digit) {
                if (digit == originalDigit) continue;
                currentStr[i] = digit;
                int nextNum = stoi(currentStr);
                if (nextNum == T) return steps + 1;
                if (nextNum >= 1000 && isPrime(nextNum) && visited.find(nextNum) == visited.end()) {
                    q.push({nextNum, steps + 1});
                    visited.insert(nextNum);
                }
            }
            currentStr[i] = originalDigit;
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
        cout << minTransformations(S, T) << endl;
    }

    return 0;
}