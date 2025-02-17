#include <iostream>
#include <stack>
#include <string>
using namespace std;

int minReversals(const string& expr) {
    int len = static_cast<int>(expr.length());

    // Nếu độ dài lẻ, không thể cân bằng được
    if (len % 2 != 0) return -1;

    stack<char> s;
    
    // Duyệt từng ký tự trong chuỗi
    for (char ch : expr) {
        if (ch == ')' && !s.empty() && s.top() == '(') {
            s.pop();  // Nếu gặp "()", loại bỏ cặp này
        } else {
            s.push(ch);  // Đẩy vào stack nếu không thể khớp
        }
    }

    int unbalanced = static_cast<int>(s.size());  // Tổng số dấu ngoặc chưa cân bằng
    int openCount = 0;  // Đếm số dấu '(' chưa khớp

    // Đếm số dấu '(' ở cuối stack
    while (!s.empty() && s.top() == '(') {
        s.pop();
        openCount++;
    }

    // Công thức tối ưu: (m+n)/2 + n%2
    return (unbalanced / 2 + openCount % 2);
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        string S;
        cin >> S;
        cout << minReversals(S) << endl;
    }

    return 0;
}