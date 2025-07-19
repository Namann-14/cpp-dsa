#include <iostream>
using namespace std;

void merge(int arr[], int start, int end) {
    int mid = start + (end - start) / 2;

    int length1 = mid - start + 1;
    int length2 = end - mid;

    // Create temporary arrays for merging
    int *first = new int[length1];
    int *second = new int[length2];

    int idx = start;
    // Copy elements to the first temporary array
    for (int i = 0; i < length1; i++) {
        first[i] = arr[idx++];
    }
    idx = mid + 1;
    // Copy elements to the second temporary array
    for (int i = 0; i < length2; i++) {
        second[i] = arr[idx++];
    }

    // Merge the two sorted arrays back into the original array
    int i = 0, j = 0, k = start;
    while (i < length1 && j < length2) {
        if (first[i] <= second[j]) {
            arr[k++] = first[i++];
        } else {
            arr[k++] = second[j++];
        }
    }

    // Copy any remaining elements from the first array
    while (i < length1) {
        arr[k++] = first[i++];
    }

    // Copy any remaining elements from the second array
    while (j < length2) {
        arr[k++] = second[j++];
    }

    // Free dynamically allocated memory
    delete[] first;
    delete[] second;
}

void mergeSort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = start + (end - start) / 2;

    // Sort the left half
    mergeSort(arr, start, mid);

    // Sort the right half
    mergeSort(arr, mid + 1, end);

    // Merge the sorted halves
    merge(arr, start, end);
}

int main() {
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
