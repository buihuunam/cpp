#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Hàm kiểm tra dấu ngoặc dư thừa
bool hasRedundantBrackets(const string &exp) {
    stack<char> s;
    
    for (char ch : exp) {
        if (ch == ')') {
            char top = s.top(); s.pop();
            bool hasOperator = false;
            
            while (!s.empty() && top != '(') {
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    hasOperator = true;
                }
                top = s.top(); s.pop();
            }
            
            if (!hasOperator) {
                return true; // Dấu ngoặc dư thừa
            }
        } else {
            s.push(ch);
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Đọc bỏ dòng xuống dòng
    
    while (T--) {
        string exp;
        getline(cin, exp);
        
        if (hasRedundantBrackets(exp)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}