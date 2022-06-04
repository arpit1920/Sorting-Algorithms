#include <iostream>
using namespace std;

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void merge(int arr[], int l, int m, int r) {
    int k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for(int j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    int i = 0;
    int j = 0;
    k = l;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size) { 
    for (int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
} 
   
int main() {
    int arr[] = {9,4,7,6,3,1,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array is: ";
    cout<<endl;
    printArray(arr, n);
    cout<<endl;
    cout<<"Array after Merge Sort is: ";
    mergeSort(arr, 0, n-1);
    cout<<endl;
    printArray(arr, n);
    cout<<endl;
    return 0;
}