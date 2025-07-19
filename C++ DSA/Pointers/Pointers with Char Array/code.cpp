#include<iostream>
using namespace std;
int main(){
/*
    int arr[] = {1,2,3,4,5};
    char ch[] = "abcd";
    cout << arr << endl; // address of first element
    cout << ch << endl; // prints entire array

    // implementation of cout is different for char and int arrray
*/
/*
    char *c = &ch[0];
    cout << c << endl;
    cout << *(c + 1) << endl;
*/
    // implementation will not stop until it encounters a null character /0;

    char z = 'z';
    char *p = &z;

    cout << *p << endl;
    cout << p << endl;
    return 0;
}