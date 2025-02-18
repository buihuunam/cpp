#include <iostream>
using namespace std;

// Hàm nhập mảng từ người dùng
void inputArray(int arr[], int n) {
    cout << "Nhap " << n << " so nguyen:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

// Hàm tìm giá trị lớn nhất trong từng cửa sổ trượt
void findMaxInWindow(int arr[], int n, int k, int result[]) {
    for (int i = 0; i <= n - k; i++) {
        int max_value = arr[i];
        for (int j = i; j < i + k; j++) {
            if (arr[j] > max_value) {
                max_value = arr[j];
            }
        }
        result[i] = max_value;
    }
}

// Hàm in mảng
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Nhập số lượng phần tử
    int n;
    cout << "Nhap so luong phan tu trong mang: ";
    cin >> n;

    // Khai báo mảng
    int num_list[n];

    // Nhập mảng từ người dùng
    inputArray(num_list, n);

    // Nhập kích thước cửa sổ k
    int k;
    cout << "Nhap kich thuoc cua so k: ";
    cin >> k;

    if (k > n || k < 1) {
        cout << "Kich thuoc cua so khong hop le!" << endl;
        return 1;
    }

    // Tạo mảng lưu kết quả
    int result[n - k + 1];

    // Tìm giá trị lớn nhất trong từng cửa sổ
    findMaxInWindow(num_list, n, k, result);

    // In kết quả
    cout << "Gia tri lon nhat trong tung cua so:" << endl;
    printArray(result, n - k + 1);

    return 0;
}
