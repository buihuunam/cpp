#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void generateExpressions(string expr, int index, int open, int close, string current, set<string>& results) {
    if (index == expr.length()) {
        if (open == close) {
            results.insert(current);
        }
        return;
    }

    if (expr[index] == '(') {
        // Include the '('
        generateExpressions(expr, index + 1, open + 1, close, current + '(', results);
        // Exclude the '('
        generateExpressions(expr, index + 1, open, close, current, results);
    } else if (expr[index] == ')') {
        if (close < open) {
            // Include the ')'
            generateExpressions(expr, index + 1, open, close + 1, current + ')', results);
        }
        // Exclude the ')'
        generateExpressions(expr, index + 1, open, close, current, results);
    } else {
        // Include the current character
        generateExpressions(expr, index + 1, open, close, current + expr[index], results);
    }
}

bool isValidExpression(const string& expr) {
    stack<char> s;
    for (char ch : expr) {
        if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            if (s.empty() || s.top() != '(') {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main() {
    string expr;
    getline(cin, expr);

    set<string> results;
    generateExpressions(expr, 0, 0, 0, "", results);

    vector<string> validExpressions;
    for (const string& e : results) {
        if (isValidExpression(e)) {
            validExpressions.push_back(e);
        }
    }

    sort(validExpressions.begin(), validExpressions.end());

    for (const string& e : validExpressions) {
        cout << e << endl;
    }

    return 0;
}