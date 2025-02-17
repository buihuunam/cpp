#include <iostream>
#include <string>
using namespace std;

string normalizeExpression(const string& expr) {
    string result;
    for (char ch : expr) {
        if (ch != '(' && ch != ')') {
            result += ch;
        }
    }
    return result;
}

bool areExpressionsEqual(const string& P1, const string& P2) {
    return normalizeExpression(P1) == normalizeExpression(P2);
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Bỏ qua ký tự newline sau số lượng bộ test

    while (T--) {
        string P1, P2;
        getline(cin, P1);
        getline(cin, P2);
        if (areExpressionsEqual(P1, P2)) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}