#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> calculateStockSpan(const vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n, 1);
    stack<int> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && prices[s.top()] <= prices[i]) {
            s.pop();
        }
        span[i] = s.empty() ? (i + 1) : (i - s.top());
        s.push(i);
    }

    return span;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> prices(N);
        for (int i = 0; i < N; ++i) {
            cin >> prices[i];
        }

        vector<int> result = calculateStockSpan(prices);
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}