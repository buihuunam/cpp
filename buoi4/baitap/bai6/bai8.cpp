#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool isValid(int num) {
    unordered_set<int> digits;
    while (num > 0) {
        int digit = num % 10;
        if (digit > 5 || digits.find(digit) != digits.end()) {
            return false;
        }
        digits.insert(digit);
        num /= 10;
    }
    return true;
}

int countValidNumbers(int L, int R) {
    int count = 0;
    for (int i = L; i <= R; ++i) {
        if (isValid(i)) {
            count++;
        }
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int L, R;
        cin >> L >> R;
        cout << countValidNumbers(L, R) << endl;
    }
    return 0;
}