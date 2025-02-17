#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string postfixToPrefix(const string& exp) {
    stack<string> s;
    int length = exp.length();

    // Đọc biểu thức từ trái sang phải
    for (int i = 0; i < length; i++) {
        // Nếu ký tự là toán hạng, đẩy vào stack
        if (isalnum(exp[i])) {
            s.push(string(1, exp[i]));
        }
        // Nếu ký tự là toán tử
        else if (isOperator(exp[i])) {
            // Lấy hai toán hạng từ stack
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();
            // Tạo biểu thức tiền tố và đẩy lại vào stack
            string temp = exp[i] + op1 + op2;
            s.push(temp);
        }
    }

    // Phần tử cuối cùng trong stack là biểu thức tiền tố
    return s.top();
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Bỏ qua ký tự newline sau số lượng bộ test

    while (T--) {
        string exp;
        getline(cin, exp);
        cout << postfixToPrefix(exp) << endl;
    }

    return 0;
}