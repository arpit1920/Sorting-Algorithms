#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void countSort(int arr[], int n) {
  int k = arr[0];
  for(int i=0; i<n; i++) {
    k = max(k, arr[i]);
  }

  int count[n] = {0};
  for(int i=0; i<n; i++) {
    count[arr[i]]++;
  }

  for(int i=1; i<=k; i++) {
    count[i]+=count[i-1];
  }

  int output[n];
  for(int i=n-1; i>=0; i--) {
    output[--count[arr[i]]]=arr[i];
  }

  for(int i=0; i<n; i++) {
    arr[i]=output[i];
  }
}

int main() {
  int arr[] = {1,3,2,3,4,1,6,4,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  printArray(arr, n);
  cout<<endl;
  cout<<"Sorted Array by Count Sort is: "<<endl;
  countSort(arr, n);
  printArray(arr, n);
  cout<<endl;
  return 0;
}
/*
Time Complexity: O(n+k)
where n is the number of elements in the input array and k is the range of input. 
Auxiliary Space: O(n+k)

The problem with the previous counting sort was that we could not sort
the elements if we have negative numbers in it. Because there are no negative array indices.
So what we do is, we find the minimum element and we will store the count of that minimum element at zero index.
*/

// Counting sort which takes negative numbers as well
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void countSort(vector<int>& arr) {
	int max = *max_element(arr.begin(), arr.end());
	int min = *min_element(arr.begin(), arr.end());
	int range = max - min + 1;
  
  vector<int> count(range), output(arr.size());
	for (int i = 0; i < arr.size(); i++)
		count[arr[i] - min]++;

	for (int i = 1; i < count.size(); i++)
		count[i] += count[i - 1];

	for (int i = arr.size() - 1; i >= 0; i--) {
		output[count[arr[i] - min] - 1] = arr[i];
		count[arr[i] - min]--;
	}

	for (int i = 0; i < arr.size(); i++)
		arr[i] = output[i];
}

void printArray(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << "\n";
}

int main() {
	vector<int> arr = { -5, -10, 0, -3, 8, 5, -1, 10 };
	countSort(arr);
	printArray(arr);
	return 0;
}