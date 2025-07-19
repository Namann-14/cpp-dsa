#include<iostream>
using namespace std;

int arrSum(int arr[], int n){
    int sum = 0;
    for (int i = 0; i < n ; i++){
        sum += arr[i];
    }
    return sum;
}
int main(){
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    int arr[n];
    for (int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    cout << "Sum of array is : " << arrSum(arr, n);
    return 0;
} 