#include<iostream>
using namespace std;

int leftMost(int arr[], int start, int end, int key){
    if (start > end){
        return -1;
    }
    int mid = start + (end - start)/2;
    if (arr[mid] == key){
        int leftIndex = leftMost(arr, start, mid - 1, key);
        return (leftIndex != -1) ? leftIndex : mid;
    }
    if (arr[mid] < key){
        return leftMost(arr, mid + 1, end, key);
    }else{
        return leftMost(arr, start, mid - 1, key);
    }
}

int rightMost(int arr[], int start, int end, int key){
    if (start > end){
        return -1;
    }
    int mid = start + (end - start)/2;
    if (arr[mid] == key){
        int rightIndex = rightMost(arr, mid + 1, end, key);
        return (rightIndex != -1) ? rightIndex : mid;
    }
    if (arr[mid] < key){
        return rightMost(arr, mid + 1, end, key);
    }else{
        return rightMost(arr, start, mid - 1, key);
    }
}

int main(){
    int arr[] = {1, 2, 3, 3, 3, 3, 3, 3, 3, 10};
    int key;
    cout << "Enter the key to search: ";
    cin >> key;
    
    int len = sizeof(arr) / sizeof(int);
    int start = 0, end = len - 1;
    cout<< "The left most and right most index are : " << leftMost(arr, start, end, key) << " , " << rightMost(arr, start, end, key);
}