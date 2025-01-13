#include <iostream>
#include <vector>
using namespace std;

int linear_search(const vector<int>& arr, int target) {
    for (size_t index = 0; index < arr.size(); ++index) {
        if (arr[index] == target) {
            return index;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {4, 2, 5, 1, 3};
    cout << linear_search(arr, 5) << endl; // Output: 2
    return 0;
}
