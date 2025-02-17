#include <iostream>
#include <queue>
#include <string>
using namespace std;

string findSmallestBDN(int N) {
    queue<string> q;
    q.push("1");

    while (!q.empty()) {
        string num = q.front();
        q.pop();

        // Chuyển đổi chuỗi thành số nguyên và kiểm tra xem nó có chia hết cho N không
        long long number = stoll(num);
        if (number % N == 0) {
            return num;
        }

        // Thêm các số mới vào hàng đợi
        q.push(num + "0");
        q.push(num + "1");
    }

    return "";
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        cout << findSmallestBDN(N) << endl;
    }

    return 0;
}