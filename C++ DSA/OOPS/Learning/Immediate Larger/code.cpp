#include<iostream>
using namespace std;

int immediateLarger(int arr[], int n, int x) {
    int curr = -1;
    for (int i = 0; i < n; i++) { 
        if (arr[i] > x) { 
            if (curr == -1 || arr[i] < curr) { 
                curr = arr[i];
            }
        }
    }
    return curr;
}

int main(){
    int n, x;
    cin>>n>>x;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout << immediateLarger(arr, n, x) << endl;
    return 0;
}