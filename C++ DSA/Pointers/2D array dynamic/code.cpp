#include<iostream>
using namespace std;
int main(){
/*
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0 ; i < n; i++){
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout <<  arr[i][j] << " ";
        }
        cout << endl;
    }
*/

/*
    int row;
    int col;

    cin >> row >> col;

    int **arr = new int *[row];
    for (int i = 0; i < row; i++){
        arr[i] = new int[col];  
    }

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cout <<  arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < row; i++){
        delete [] arr[i];  
    }
    delete arr;
*/

int row;
    cout << "Enter the number of rows: ";
    cin >> row;

    // Define the sizes for each row
    int sizes[] = {1, 2, 3, 2, 1}; // Ensure this has at least 'row' elements
    if (row > sizeof(sizes) / sizeof(sizes[0])) {
        cout << "Error: Not enough sizes defined for the rows." << endl;
        return 1;
    }

    // Dynamically allocate the 2D array
    int **arr = new int *[row];
    for (int i = 0; i < row; i++) {
        arr[i] = new int[sizes[i]];
    }

    // Populate the array
    cout << "Enter the elements for the array:" << endl;
    for (int i = 0; i < row; i++) {
        cout << "Row " << i + 1 << " (" << sizes[i] << " elements): ";
        for (int j = 0; j < sizes[i]; j++) {
            cin >> arr[i][j];
        }
    }

    // Print the array
    cout << "\nThe 2D array is:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Free the allocated memory
    for (int i = 0; i < row; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}