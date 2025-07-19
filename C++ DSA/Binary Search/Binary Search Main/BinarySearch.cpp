#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 6, 6, 7, 8, 9, 10, 13};
    int key;
    cout << "Enter the key to search: ";
    cin >> key;
    
    int len = sizeof(arr) / sizeof(int);
    int start = 0, end = len - 1, mid;
    bool found = false;

    while (start <= end) {
        mid = start + (end - start) / 2;
        if (arr[mid] == key) {
            cout << "Index of key is: " << mid << endl;
            found = true;
            break;
        } else if (arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    if (!found) {
        cout << "Key not found in the array." << endl;
    }

    return 0;
}
