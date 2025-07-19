#include<iostream>
using namespace std;

int MaxElement(int arr[], int s, int e) {
    if (s == e) { 
        // Base case: only one element
        return s;
    }
    int mid = s + (e - s) / 2;

    // Compare mid and mid+1 to decide the direction
    if (arr[mid] < arr[mid + 1]) {
        return MaxElement(arr, mid + 1, e); // Maximum is on the right
    } else {
        return MaxElement(arr, s, mid); // Maximum is on the left
    }
}

int main(){
    int arr[] = {1,7,5,3,2,1};
    int s = 0;
    int e = sizeof(arr)/sizeof(int) -1 ;
    cout << "Max element in array is: " << arr[MaxElement(arr, s, e)];
    return 0;
}