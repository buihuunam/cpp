#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<string> generateBinaryNumbers(int n) {
    vector<string> result;
    queue<string> q;
    q.push("1");

    while (n--) {
        string s1 = q.front();
        q.pop();
        result.push_back(s1);

        string s2 = s1;
        q.push(s1 + "0");
        q.push(s2 + "1");
    }

    return result;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<string> binaryNumbers = generateBinaryNumbers(n);
        for (const string& num : binaryNumbers) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}