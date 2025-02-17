#include <iostream>
#include <stack>
#include <string>
using namespace std;

string findSmallestNumber(const string& S) {
    stack<int> st;
    string result;
    int num = 1;

    for (char ch : S) {
        st.push(num++);
        if (ch == 'I') {
            while (!st.empty()) {
                result += to_string(st.top());
                st.pop();
            }
        }
    }

    st.push(num++);
    while (!st.empty()) {
        result += to_string(st.top());
        st.pop();
    }

    return result;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Bỏ qua ký tự newline sau số lượng bộ test

    while (T--) {
        string S;
        getline(cin, S);
        cout << findSmallestNumber(S) << endl;
    }

    return 0;
}