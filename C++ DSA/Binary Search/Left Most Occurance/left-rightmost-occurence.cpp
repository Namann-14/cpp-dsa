#include<iostream>
using namespace std;
int main(){
    int arr[] = {1, 2, 3, 3, 3, 3, 3, 3, 3, 10};
    int key;
    cout << "Enter the key to search: ";
    cin >> key;
    
    int len = sizeof(arr) / sizeof(int);
    int start = 0, end = len - 1, mid;
    int leftmost = -1;
    int rightmost = -1;

    // leftmost occurrence 
    while (start <= end){
        mid = start + (end - start)/2;
        if (arr[mid] == key){
            leftmost = mid;
            end = mid - 1;
        }else if (arr[mid] < key){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    
     start = 0, end = len - 1;
    // rightmost occurrence 
    while (start <= end){
        mid = start + (end - start)/2;
        if (arr[mid] == key){
            rightmost = mid;
            start = mid + 1;
        }else if (arr[mid] < key){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    cout<< "The left most and right most index are : " << leftmost << " , " << rightmost;
    return 0;
}