#include<iostream>
using namespace std;

int sumArr(int *arr, int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main(){
/*
    int *i = new int;
    *i = 5;
    cout << *i << endl;
    cout << i << endl;
    delete i;
*/
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }


    cout << "Sum of elements is: " << sumArr(arr, n) << endl;

    delete []arr;

    return 0;
}