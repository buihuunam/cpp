#include<iostream>
#include<vector>
using namespace std;

//merge 2 sorted arrays
void merge(vector<int> &arr, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    //create 2 temp arrays
    vector<int> L(n1), R(n2);

    //copy data to temp arrays L[] and R[]
    for(int i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = arr[m + 1 + i];
    }

    //merge the temp arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int l, int r){
    if(l < r){
        //same as (l+r)/2, but avoids overflow for large l and r
        int m = l + (r - l) / 2;
        //sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main(){
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    mergeSort(arr, 0, arr.size()-1);
    cout << "Sorted array: ";
    for(int x: arr){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}