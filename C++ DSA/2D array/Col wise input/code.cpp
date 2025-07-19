#include <iostream>
using namespace std;

int main() {
    int row, col;

    cin >> row >> col;

    // Declare a 2D array
    int arr[row][col];

    // Input the elements column by column
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            cin >> arr[j][i];
        }
    }

    // Output the elements row by row
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " "; // Add space for better readability
        }
        cout << endl; // Move to the next row
    }

    return 0;
}
