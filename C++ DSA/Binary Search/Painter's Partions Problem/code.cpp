#include <iostream>
using namespace std;

// Function to check if the painting is possible within the given time (mid)
bool isPossible(int arr[], int m, int n, int mid) {
    int cnt = 1;  // Number of painters used
    int boardSum = 0;

    for (int i = 0; i < n; i++) {
        if (boardSum + arr[i] <= mid) {
            boardSum += arr[i];
        } else {
            cnt++;
            if (cnt > m || arr[i] > mid) {
                return false;
            }
            boardSum = arr[i];
        }
    }
    return true;
}

int main() {
    int painter;
    cin >> painter;
    int board;
    cin >> board;
    int *arr = new int[board];

    // Input board lengths
    for (int i = 0; i < board; i++) {
        cin >> arr[i];
    }

    // Calculate the total sum and maximum element in the array
    int sum = 0, maxBoard = 0;
    for (int i = 0; i < board; i++) {
        sum += arr[i];
        maxBoard = max(maxBoard, arr[i]);
    }

    // Binary search on the possible range of maximum time
    int start = maxBoard;  // Minimum time = largest board
    int end = sum;         // Maximum time = total length of boards
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isPossible(arr, painter, board, mid)) {
            ans = mid;      // Update answer
            end = mid - 1;  // Try for a smaller maximum time
        } else {
            start = mid + 1;  // Try for a larger maximum time
        }
    }

    cout << ans;

    delete[] arr;  // Free the dynamically allocated memory
    return 0;
}
