#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    long sum = 0;
    for (int i = 0; i<n; i++){
        sum+=arr[i];
    }

    cout << sum;

    delete[] arr;
    return 0;
}