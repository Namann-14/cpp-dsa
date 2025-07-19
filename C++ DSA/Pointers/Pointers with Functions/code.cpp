#include<iostream>
using namespace std;

void show(int *p){
    cout << p <<endl;
    cout << *p <<endl;
}

void updateArr(int *p){
    *p += 1;
}   

int getSum(int arr[], int n){
    cout << sizeof(arr) << endl;
    int sum = 0;
    for (int i = 0; i < 5; i++){
        sum += arr[i];
    }
    return sum;
}

int sizeArr(int &arr){
    return sizeof(arr);
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int *p = &arr[0];
    // show(p);
    // updateArr(p);
    // cout << arr[0];

    cout << getSum(arr, 5) << endl;
    cout << sizeArr(*arr);

    return 0;
}