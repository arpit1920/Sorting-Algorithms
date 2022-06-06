/* converting Worst Case to Best case in Quick Sort,
mid = low + (high - low)/2
pivot = mid
*/

#include <iostream>
using namespace std; 
void swap(int arr[], int a, int b) { 
    int t = arr[a]; 
    arr[a] = arr[b]; 
    arr[b] = t; 
} 

int partition (int arr[], int low, int high) {
    // pivot
    int pivot = arr[high]; 
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++) { 
        //if current element is smaller than pivot, increment the low element
        //swap elements at i and j
        if (arr[j] <= pivot) {
            // increment index of smaller element
            i++; 
            swap(arr,i,j);
          }
    }
    swap(arr, i+1, high); 
    return (i + 1); 
} 
   
//quicksort algorithm
void quickSort(int arr[], int low, int high) { 
    if (low < high) { 
        //partition the array 
        int pivot = partition(arr, low, high); 
        //sort the sub arrays independently 
        quickSort(arr, low, pivot - 1); 
        quickSort(arr, pivot + 1, high); 
    } 
} 
   
void displayArray(int arr[], int size) { 
    int i; 
    for (i=0; i < size; i++) {
        cout<<arr[i]<<" ";
    }
} 
   
int main() { 
    int arr[] = {4,6,2,5,7,9,1,3}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout<<"Input array"<<endl;
    displayArray(arr,n);
    cout<<endl;
    quickSort(arr, 0, n-1); 
    cout<<"Array sorted with quick sort"<<endl; 
    displayArray(arr,n);
    cout<<endl;
    return 0;
}