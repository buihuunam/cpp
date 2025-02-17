#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

// Hàm kiểm tra xem hai xâu có khác nhau duy nhất một ký tự hay không
bool isAdjacent(const string& a, const string& b) {
    int count = 0;
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] != b[i]) {
            count++;
        }
        if (count > 1) {
            return false;
        }
    }
    return count == 1;
}

int shortestPathLength(const vector<string>& words, const string& start, const string& end) {
    unordered_set<string> wordSet(words.begin(), words.end());
    if (wordSet.find(end) == wordSet.end()) {
        return -1;
    }

    queue<pair<string, int>> q;
    q.push({start, 1});
    wordSet.erase(start);

    while (!q.empty()) {
        string currentWord = q.front().first;
        int currentLength = q.front().second;
        q.pop();

        for (auto it = wordSet.begin(); it != wordSet.end();) {
            if (isAdjacent(currentWord, *it)) {
                if (*it == end) {
                    return currentLength + 1;
                }
                q.push({*it, currentLength + 1});
                it = wordSet.erase(it);
            } else {
                ++it;
            }
        }
    }

    return -1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        vector<string> words(n);
        for (int i = 0; i < n; ++i) {
            cin >> words[i];
        }

        int result = shortestPathLength(words, s, t);
        cout << result << endl;
    }

    return 0;
}