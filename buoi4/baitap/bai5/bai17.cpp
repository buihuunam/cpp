#include <iostream>
#include <stack>
#include <string>
using namespace std;

int longestValidParentheses(const string& s) {
    stack<int> st;
    int maxLength = 0;
    st.push(-1); // Khởi tạo stack với giá trị -1 để tính toán độ dài

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i);
            } else {
                maxLength = max(maxLength, i - st.top());
            }
        }
    }

    return maxLength;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Bỏ qua ký tự newline sau số lượng bộ test

    while (T--) {
        string S;
        getline(cin, S);
        cout << longestValidParentheses(S) << endl;
    }

    return 0;
}