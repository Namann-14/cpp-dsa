#include <iostream>
using namespace std;

class Matrix {
public:
    int Row;
    int Col;
    int **Mat;

    // Constructor to allocate memory for the matrix
    Matrix(int m, int n) {
        this->Row = m;
        this->Col = n;
        Mat = new int *[Row];
        for (int i = 0; i < Row; i++) {
            Mat[i] = new int[Col];
        }
    }

    // Method to input the matrix
    void makeMatrix() {
        cout << "Enter elements for a " << Row << "x" << Col << " matrix:" << endl;
        for (int i = 0; i < Row; i++) {
            for (int j = 0; j < Col; j++) {
                cin >> Mat[i][j];
            }
        }
    }

    // Method to display the matrix
    void displayMatrix() {
        cout << "The matrix is:" << endl;
        for (int i = 0; i < Row; i++) {
            for (int j = 0; j < Col; j++) {
                cout << Mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Overloaded + operator
    Matrix operator+(Matrix &m) {
        Matrix result(Row, Col); // Create result matrix
        for (int i = 0; i < Row; i++) {
            for (int j = 0; j < Col; j++) {
                result.Mat[i][j] = Mat[i][j] + m.Mat[i][j];
            }
        }
        return result;
    }


};

int main() {
    // Create and input two matrices
    Matrix m1(3, 3);
    m1.makeMatrix();
    Matrix m2(3, 3);
    m2.makeMatrix();

    // Display the input matrices
    cout << "Matrix 1:" << endl;
    m1.displayMatrix();
    cout << "Matrix 2:" << endl;
    m2.displayMatrix();


    Matrix Result = m1 + m2;
    cout << "Resultant Matrix after addition:" << endl;
    Result.displayMatrix();
    
    return 0;
}
