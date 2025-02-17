#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodeString(const string& s) {
    stack<string> strStack;
    stack<int> numStack;
    string currentStr;
    int currentNum = 0;

    for (char ch : s) {
        if (isdigit(ch)) {
            currentNum = currentNum * 10 + (ch - '0');
        } else if (ch == '[') {
            numStack.push(currentNum);
            strStack.push(currentStr);
            currentNum = 0;
            currentStr.clear();
        } else if (ch == ']') {
            string temp = currentStr;
            currentStr = strStack.top();
            strStack.pop();
            int repeatTimes = numStack.top();
            numStack.pop();
            while (repeatTimes--) {
                currentStr += temp;
            }
        } else {
            currentStr += ch;
        }
    }

    return currentStr;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Bỏ qua ký tự newline sau số lượng bộ test

    while (T--) {
        string str;
        getline(cin, str);
        cout << decodeString(str) << endl;
    }

    return 0;
}