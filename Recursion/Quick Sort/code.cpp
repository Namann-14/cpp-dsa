#include<iostream>
using namespace std;

int partition(int arr[], int start, int end){
    // Declaring a Pivot
    int pivot = arr[start];
    
    // Checking the number of elements smaller than pivot
    int count = 0;
    for (int i = start + 1; i <= end; i++){
        if (arr[i] < pivot){
            count++;
        }
    }

    // Placing Pivot at the right position
    
    int pivotIdx = start + count;
    swap(arr[pivotIdx], arr[start]);

    // Left and Right wala part sambhal lete hai

    int i = start;
    int j = end;

    while( i < pivotIdx && j > pivotIdx ){
        while (arr[i] < pivot){
            i++;
        }
        while (arr[j] > pivot){
            j--;
        }
        if ( i < pivotIdx && j > pivotIdx ){
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIdx;

}

void quickSort(int arr[], int start, int end){
    // Base Case: if array mein 0 ya 1 element ho toh alr sorted hai
    if (start >= end){
        return;
    }

    // Finding pivot 
    int p = partition(arr, start, end);

    // Sorting Left Half
    quickSort(arr, start, p - 1);

    // Sorting Right Half
    quickSort(arr, p + 1, end);

}

int main(){
    int arr[25] = {23, 54, 54, 845, 14, 47, 74, 7, 447, 44, 44, 40, 0, 0, 0, 5, 1, 57, 8, 2, 2, 4, 82, 566, 4};
    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]) - 1;

    quickSort(arr, start, end);

    // Print the sorted array
    for (int i = 0; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}