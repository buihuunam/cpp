#include <iostream>
#include <queue>
#include <string>
using namespace std;

int countBDN(long long N) {
    queue<string> q;
    q.push("1");
    int count = 0;

    while (!q.empty()) {
        string num = q.front();
        q.pop();

        // Chuyển đổi chuỗi thành số nguyên và kiểm tra xem nó có nhỏ hơn N không
        long long number = stoll(num);
        if (number >= N) {
            break;
        }

        count++;

        // Thêm các số mới vào hàng đợi
        q.push(num + "0");
        q.push(num + "1");
    }

    return count;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long N;
        cin >> N;
        cout << countBDN(N) << endl;
    }

    return 0;
}