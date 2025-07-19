#include <iostream>
using namespace std;

int main() {
    int arr[6] = {1, 3, 3, 5, 7, 9};
    int start = 0;
    int end = 5;
    int target;
    cin >> target;
    int ans = -1; // Initialize ans to handle cases where no lower bound is found.

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] < target) {
            start = mid + 1;
        } else {
            ans = mid; // Record potential lower bound.
            end = mid - 1; // Look for earlier occurrences.
        }
    }

    if (ans != -1) {
        cout << "Lower bound index: " << ans;
    } else {
        cout << "No lower bound found for the target.";
    }

    return 0;
}
