#include<iostream>
#include<vector>
using namespace std;

//quick sort
int partition(vector<int> &arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            //swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //swap arr[i+1] and arr[high]
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}

void quickSort(vector<int> &arr, int low, int high){
    if(low < high){
        //find pivot element such that
        int pi = partition(arr, low, high);
        //call quickSort on the left of pivot
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main(){
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    quickSort(arr, 0, arr.size()-1);
    cout << "Sorted array: ";
    for(int x: arr){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
