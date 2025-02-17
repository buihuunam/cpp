#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int longestValidParenthesesSum(const string& s) {
    int n = s.length();
    stack<int> st;
    vector<bool> valid(n, false);

    // Sử dụng stack để đánh dấu các vị trí của các ký tự ngoặc đúng
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else if (!st.empty()) {
            valid[i] = true;
            valid[st.top()] = true;
            st.pop();
        }
    }

    // Tính tổng độ dài của các biểu thức con viết đúng
    int maxLength = 0, currentLength = 0;
    for (int i = 0; i < n; ++i) {
        if (valid[i]) {
            currentLength++;
        } else {
            maxLength += (currentLength / 2) * 2;
            currentLength = 0;
        }
    }
    maxLength += (currentLength / 2) * 2;

    return maxLength;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Bỏ qua ký tự newline sau số lượng bộ test

    while (T--) {
        string P;
        getline(cin, P);
        cout << longestValidParenthesesSum(P) << endl;
    }

    return 0;
}