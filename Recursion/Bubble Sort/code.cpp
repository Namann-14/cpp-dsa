#include<iostream>
using namespace std;

void BubbleSort(int arr[], int n){
    // Base Case already sorted
    if (n == 0 || n == 1){
        return;
    }
    for (int i = 0; i < n - 1; i++){
        if (arr[i] > arr[i + 1]){
            swap(arr[i], arr[i + 1]);
        }
    }
    BubbleSort(arr, n - 1); // Recursive call to sort the rest of the array
}

int main(){
    int arr[5] = {2, 5, 1, 6, 9};
    BubbleSort(arr, 5); // Sort the array

    // Printing the sorted array
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
