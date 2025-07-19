#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void SelectionSort(vector<int> &arr, int size, int start = 0){
    // Base Case: Entire Array is Sorted
    if (start >= size - 1){
        return;
    }

    int minIdx = start;
    for (int i = start + 1; i < size; i++){
        if (arr[i] < arr[minIdx]){
            minIdx = i;
        }
    }
    swap(arr[start], arr[minIdx]);
    
    SelectionSort(arr, size, start + 1);
}


int main() {
    vector<int> arr;
    int size;
    
    cout << "Enter the size of the array: ";
    cin >> size;
    
    // Input the elements of the array
    for (int i = 0; i < size; i++) {
        int value;
        cout << "Enter value for index " << i << ": ";
        cin >> value;
        arr.push_back(value);  // Push the value to the vector
    }

    SelectionSort(arr, size);


    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}