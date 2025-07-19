#include<iostream>
using namespace std;
int main(){
    int arr[] = {10,1,7,6,14,9};
    int size = sizeof(arr)/sizeof(int);
    for (int i = 0; i < size - 1; i++){
        bool isSwapped = false;
        for(int j = 0; j < size - i - 1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSwapped = true;
            }
        }
        if (isSwapped == false){
            break;
        }
    }
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    return 0;
}