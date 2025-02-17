#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> findNextGreaterFrequency(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    unordered_map<int, int> freq;
    stack<int> s;

    // Đếm số lần xuất hiện của mỗi phần tử
    for (int num : arr) {
        freq[num]++;
    }

    // Duyệt qua mảng từ phải sang trái
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && freq[arr[s.top()]] <= freq[arr[i]]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = arr[s.top()];
        }
        s.push(i);
    }

    return result;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        vector<int> result = findNextGreaterFrequency(arr);
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}