#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

int evaluatePostfix(const string& exp) {
    stack<int> s;
    int length = exp.length();

    for (int i = 0; i < length; i++) {
        // Nếu ký tự là toán hạng, đẩy vào stack
        if (isdigit(exp[i])) {
            s.push(exp[i] - '0');
        }
        // Nếu ký tự là toán tử
        else {
            int op2 = s.top(); s.pop();
            int op1 = s.top(); s.pop();
            int result;
            switch (exp[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = pow(op1, op2); break;
                default: result = 0; break;
            }
            s.push(result);
        }
    }

    // Phần tử cuối cùng trong stack là kết quả của biểu thức
    return s.top();
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Bỏ qua ký tự newline sau số lượng bộ test

    while (T--) {
        string exp;
        getline(cin, exp);
        cout << evaluatePostfix(exp) << endl;
    }

    return 0;
}