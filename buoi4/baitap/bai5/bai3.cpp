#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

string removeParentheses(string expr) {
    stack<int> s;
    string result;
    int n = expr.length();
    vector<bool> remove(n, false);

    for (int i = 0; i < n; ++i) {
        if (expr[i] == '(') {
            s.push(i);
        } else if (expr[i] == ')') {
            int j = s.top();
            s.pop();
            if (j > 0 && expr[j - 1] == '-') {
                for (int k = j + 1; k < i; ++k) {
                    if (expr[k] == '+') {
                        expr[k] = '-';
                    } else if (expr[k] == '-') {
                        expr[k] = '+';
                    }
                }
            }
            remove[j] = true;
            remove[i] = true;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!remove[i]) {
            result += expr[i];
        }
    }

    return result;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Bỏ qua ký tự newline sau số lượng bộ test

    while (T--) {
        string P;
        getline(cin, P);
        cout << removeParentheses(P) << endl;
    }

    return 0;
}