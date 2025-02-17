#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>
#include <cmath>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(const string& exp) {
    stack<char> s;
    string result;
    stringstream ss(exp);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            result += token + ' ';
        } else if (token == "(") {
            s.push('(');
        } else if (token == ")") {
            while (!s.empty() && s.top() != '(') {
                result += s.top();
                result += ' ';
                s.pop();
            }
            s.pop(); // Pop the '('
        } else {
            while (!s.empty() && precedence(s.top()) >= precedence(token[0])) {
                result += s.top();
                result += ' ';
                s.pop();
            }
            s.push(token[0]);
        }
    }

    while (!s.empty()) {
        result += s.top();
        result += ' ';
        s.pop();
    }

    return result;
}

int evaluatePostfix(const string& exp) {
    stack<int> s;
    stringstream ss(exp);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            s.push(stoi(token));
        } else {
            int op2 = s.top(); s.pop();
            int op1 = s.top(); s.pop();
            int result;
            switch (token[0]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                default: result = 0; break;
            }
            s.push(result);
        }
    }

    return s.top();
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Bỏ qua ký tự newline sau số lượng bộ test

    while (T--) {
        string exp;
        getline(cin, exp);
        string postfix = infixToPostfix(exp);
        cout << evaluatePostfix(postfix) << endl;
    }

    return 0;
}