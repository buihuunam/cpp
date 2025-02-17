#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> findNextGreaterElements(const vector<int>& arr) {
    int n = arr.size();
    vector<int> nextGreater(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            nextGreater[i] = s.top();
        }
        s.push(arr[i]);
    }

    return nextGreater;
}

vector<int> findNextSmallerElements(const vector<int>& arr) {
    int n = arr.size();
    vector<int> nextSmaller(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            nextSmaller[i] = s.top();
        }
        s.push(arr[i]);
    }

    return nextSmaller;
}

vector<int> findResult(const vector<int>& arr) {
    vector<int> nextGreater = findNextGreaterElements(arr);
    vector<int> result(arr.size(), -1);

    for (int i = 0; i < arr.size(); ++i) {
        if (nextGreater[i] != -1) {
            vector<int> subArr(arr.begin() + i + 1, arr.end());
            vector<int> nextSmaller = findNextSmallerElements(subArr);
            for (int j = 0; j < subArr.size(); ++j) {
                if (subArr[j] == nextGreater[i]) {
                    result[i] = nextSmaller[j];
                    break;
                }
            }
        }
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

        vector<int> result = findResult(arr);
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}