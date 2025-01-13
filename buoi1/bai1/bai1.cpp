#include <iostream>
using namespace std;

int sum_1_to_n(int n) {
    int s = 0; // 1 phép gán
    for(int i = 1; i <= n; i++) { // n lần lặp
        s += i; // 1 phép cộng và 1 phép gán mỗi lần lặp
    }
    return s;
}

int main() {
    int n = 5;
    cout << "Tong 1..n = " << sum_1_to_n(n) << endl; // Output: 15
    return 0;
}
