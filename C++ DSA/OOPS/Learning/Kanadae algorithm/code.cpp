#include<iostream>
using namespace std;

int maxSubArray(int arr[], int n){
    int curr = -1;
    int sum = 0;
    for (int i = 0; i < n ; i++){
        if (sum < 0){
            sum = 0;
        }
        sum += arr[i];
        curr = max(curr, sum);
    }
    return curr;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    cout << maxSubArray(arr,n);
    
    return 0;
}