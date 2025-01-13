#include<iostream>
#include<vector>
using namespace std;

//hàm bubble sort
void bubbleSort(vector<int> &arr){
    int n = arr.size();
    bool swapped;
    for(int i = 0; i < n-1; i++){
        swapped = false;
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

int main(){
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(arr);
    cout << "Sorted array: ";
    for(int x: arr){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}