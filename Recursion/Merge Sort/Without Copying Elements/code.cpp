#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int start, int end) {
    int mid = start + (end - start) / 2;

    int i = start;       // Start of the left subarray
    int j = mid + 1;     // Start of the right subarray
    int k = 0;           // Index for the temporary array

    // Temporary array to store the merged result
    vector<int> temp(end - start + 1);

    // Merge the two subarrays in sorted order
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements from the left subarray, if any
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from the right subarray, if any
    while (j <= end) {
        temp[k++] = arr[j++];
    }

    // Copy the merged elements back to the original array
    for (int t = 0; t < temp.size(); t++) {
        arr[start + t] = temp[t];
    }
}

void mergeSort(int arr[], int start, int end){
    if (start >= end){
        return;
    }
    int mid = start + (end - start)/2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, end);
}

int main(){
    int arr[25] = {23, 54, 54, 845, 14, 47, 74, 7, 447, 44, 44, 40, 0, 0, 0, 5, 1, 57, 8, 2, 2, 4, 82, 566, 4};
    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]) - 1;

    mergeSort(arr, start, end);

    // Print the sorted array
    for (int i = 0; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}