#include<iostream>
using namespace std;
void insertionSort(int arr[], int n) {
    for(int i=0; i<n; i++) {
        int temp = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int a[] = {4,8,1,5,9,2};
    int n = sizeof(a)/sizeof(a[0]);
    insertionSort(a, 6);
    printArray(a, 6);
    return 0;
}