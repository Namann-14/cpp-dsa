#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

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
    
    // SELECTION SORT
    for (int i = 0; i < arr.size() - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
    
    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
