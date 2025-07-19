#include<iostream>
using namespace std;
void swapAlt(int arr[], int size){

    for (int i = 0 ; i < size - 1 ; i+=2){
        swap(arr[i],arr[i+1]);
    }
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(int);
    swapAlt(arr,size);
    for (int i = 0; i < size ; i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}