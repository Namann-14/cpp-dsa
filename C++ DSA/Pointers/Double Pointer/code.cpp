#include<iostream>
using namespace std;
int main(){
    int i = 5;
    int *p = &i;
    int **q = &p;

    cout << endl << endl << "Sab sahi chal raha hai" << endl << endl;

    cout << i << endl;
    cout << &i << endl;

    cout << endl;

    cout << p << endl;
    cout << &p << endl;
    cout << *p << endl;

    cout << endl;

    cout << q << endl;
    cout << *q << endl;
    cout << **q << endl;
    cout << &q << endl;


    return 0;
}