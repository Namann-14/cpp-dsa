#include <iostream>
using namespace std;

// Recursive function to find the target element in the array
bool isFound(int arr[], int n, int target) {
    if (n == 0) { // Base case: no elements left to check
        return false;
    }
    if (arr[0] == target) { // If the first element matches the target
        return true;
    }
    return isFound(arr + 1, n - 1, target); // Recursive call with the rest of the array
}

int main() {
    int arr[] = {1, 2, 3, 4, 5}; // Sample array
    int target; // Element to search
    cin >> target; // Input the target element

    // Check if the target is in the array and output the result
    if (isFound(arr, 5, target)) {
        cout << "Element is present";
    } else {
        cout << "Element is not present";
    }
    return 0;
}
