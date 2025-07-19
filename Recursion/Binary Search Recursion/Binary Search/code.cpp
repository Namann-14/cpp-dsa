#include<iostream>
using namespace std;

bool BinarySearch(int arr[], int start, int end, int target){
    if (start > end){
        return false;
    }
    int mid = start + (end - start)/2;

    if (arr[mid] == target){
        return true;
    }
    if (arr[mid] < target){
        return BinarySearch(arr, mid + 1, end, target);
    }else{
        return BinarySearch(arr, start, mid - 1, target);
    }
}

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int target;
    cin >> target;
    int start = 0;
    int end = 9;
    cout << "Target found" << BinarySearch(arr, start, end, target);
    return 0;
}