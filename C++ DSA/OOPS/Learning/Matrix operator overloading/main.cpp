#include<iostream>
using namespace std;
class Matrix{
    public:
        int row;
        int col;
        int **mat;
        Matrix(){
        }
        Matrix(int row, int col){
            this -> row = row;
            this -> col = col;
            mat = new int *[row];
            for (int i = 0 ; i < row ; i ++){
                mat[row] = new int [col];
            }
            for (int i = 0 ; i < row ; i++){
                for (int j = 0 ; j < col ; j++){
                    cin >>mat[i][j];
                }
            }
        }
        Matrix operator+(Matrix &m){
            Matrix result(row, col);
            for (int i = 0 ; i < row ; i++){
                for (int j = 0 ; j < col ; j++){
                    result.mat[i][j] += mat[i][j] + m.mat[i][j];
                }
            }
            return result;
        }
        void display(){
            for (int i = 0 ; i < row ; i++){
                for (int j = 0 ; j < col ; j++){
                    cout << mat[i][j];
                }
            }
        }

};
int main(){
    Matrix m1(3,3);
    Matrix m2(3,3);
    Matrix m3 = m1 + m2;
    m3.display();
    return 0;
}