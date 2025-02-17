#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> generateLocPhatNumbers(int N) {
    vector<string> result;
    queue<string> q;
    q.push("6");
    q.push("8");

    while (!q.empty()) {
        string num = q.front();
        q.pop();

        if (num.length() > N) {
            break;
        }

        result.push_back(num);

        q.push(num + "6");
        q.push(num + "8");
    }

    sort(result.begin(), result.end()); // Sắp xếp theo thứ tự tăng dần
    return result;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<string> locPhatNumbers = generateLocPhatNumbers(N);
        cout << locPhatNumbers.size() << endl;
        for (const string& num : locPhatNumbers) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}