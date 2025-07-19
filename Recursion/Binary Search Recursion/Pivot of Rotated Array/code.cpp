#include<iostream>
using namespace std;

int Pivot(int arr[], int s, int e){
    if (s == e) { 
        // Base case: single element is the pivot
        return s;
    }

    int mid = s + (e - s) / 2;

    // Check if mid is the pivot
    if (mid < e && arr[mid] > arr[mid + 1]) {
        return mid + 1;
    }

    // Check if mid-1 is the pivot
    if (mid > s && arr[mid] < arr[mid - 1]) {
        return mid;
    }

    // Decide the direction to search
    if (arr[mid] >= arr[s]) {
        return Pivot(arr, mid + 1, e); // Pivot is in the right half
    } else {
        return Pivot(arr, s, mid - 1); // Pivot is in the left half
    }
}

int main(){
    int arr[] = {7,9,1,2,3};
    int s = 0;
    int e = sizeof(arr)/sizeof(int) - 1 ;
    cout << "Pivot of array is: " << arr[Pivot(arr, s,e)] << endl;
    return 0;
}