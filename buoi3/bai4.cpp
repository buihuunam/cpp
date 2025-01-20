#include <iostream>
#include <stack>
#include <string>

using namespace std;

string decimal_to_binary(int n) {
    stack<int> s;
    cout << "convert " << n << " to binary" << endl;

    if (n == 0) {
        s.push(0);
        cout << "pushed 0 to stack" << endl;
    } else {
        while (n > 0) {
            int remainder = n % 2;
            s.push(remainder);
            cout << "pushed " << remainder << " to stack" << endl;
            n = n / 2;
            cout << "n = " << n << endl;
        }
    }

    string binary = "";
    cout << "pop all elements from stack" << endl;
    while (!s.empty()) {
        binary += to_string(s.top());
        cout << "popped " << s.top() << " from stack" << endl;
        s.pop();
    }
    return binary;
}

int main() {
    int number = 10;
    string binary = decimal_to_binary(number);
    cout << "Binary representation of " << number << " is: " << binary << endl;
    return 0;
}