#include<iostream>
#include<vector>
using namespace std;

//selection sort
void selectionSort(vector<int> &arr){
    int n = arr.size();
    for(int i = 0; i < n-1; i++){
        int min_idx = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        //swap arr[i] and arr[min_idx]
        if(min_idx != i){
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

int main(){
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    selectionSort(arr);
    cout << "Sorted array: ";
    for(int x: arr){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}