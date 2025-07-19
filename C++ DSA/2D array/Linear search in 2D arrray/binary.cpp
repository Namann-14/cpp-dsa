#include <iostream>
using namespace std;

int main() {
    // Initialize the matrix
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    // Input target
    int target;
    cin >> target;
    
    // Binary search variables
    int start = 0;
    int end = 8; // Total elements - 1 (3 * 3 - 1)
    
    // Binary search
    while (start <= end) {
        int mid = start + (end - start) / 2;
        int element = arr[mid / 3][mid % 3]; // Convert 1D index to 2D indices
        
        if (element == target) {
            cout << "Found" << endl;
            return 0; // Exit after finding the target
        } else if (element < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    
    // If we exit the loop, target was not found
    cout << "Not Found" << endl;
    return 0;
}
