#include<iostream>
using namespace std;

int Sum(int arr[], int n){
    // Base Case
    if (n == 0){
        return 0;
    }
    return arr[0] + Sum(arr + 1, n - 1);
}

int main(){
    int arr[5] = {3,2,5,1,6};
    cout << "Sum of Array is: "<< Sum(arr,5) << endl;
    return 0;
}