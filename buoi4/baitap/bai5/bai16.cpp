#include <iostream>
#include <stack>
#include <vector>
using namespace std;

long long largestRectangleArea(const vector<int>& heights) {
    int n = heights.size();
    stack<int> s;
    long long maxArea = 0;
    int i = 0;

    while (i < n) {
        if (s.empty() || heights[s.top()] <= heights[i]) {
            s.push(i++);
        } else {
            int h = heights[s.top()];
            s.pop();
            long long width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, h * width);
        }
    }

    while (!s.empty()) {
        int h = heights[s.top()];
        s.pop();
        long long width = s.empty() ? i : i - s.top() - 1;
        maxArea = max(maxArea, h * width);
    }

    return maxArea;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> heights(N);
        for (int i = 0; i < N; ++i) {
            cin >> heights[i];
        }

        cout << largestRectangleArea(heights) << endl;
    }

    return 0;
}