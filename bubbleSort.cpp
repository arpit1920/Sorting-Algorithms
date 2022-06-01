/*
Without optimization approach, we get the sorting = 866 ms
With Optimized Approach =  we get the sorting = 990ms
*/
#include<iostream>
using namespace std;

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        bool swapped = false;
        for(int j=0; j<n-i-1; j++) {
            if(arr[j+1]<arr[j]) {
                swapped = true;
                swap(arr[j+1], arr[j]);
            }
        }
        if(!swapped) {
            break;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int a[] = {4,3,7,1,5};
    int n = sizeof(a)/sizeof(a[0]);
    bubbleSort(a,n);
    printArray(a,n);
    return 0;
}

/*
TC = O(N*N)
with optimization TC = O(N)
*/