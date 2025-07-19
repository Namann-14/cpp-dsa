#include<iostream>
using namespace std;

int LowerBound(int arr[], int start, int end, int target){
    if (start > end){
        return -1;
    }

    int mid = start + (end - start)/2;

    if (arr[mid] < target){
        return LowerBound(arr, mid + 1, end, target);
    }else{
        int ans = LowerBound(arr, start, mid - 1, target);
        return (ans != -1) ? ans : mid;
    }
}

int main(){
    int arr[6] = {1, 3, 3, 5, 7, 9};
    int start = 0;
    int end = 5;
    int target;
    cin >> target;
    cout << "Lower bound of " << target << " is: " << arr[LowerBound(arr,start,end,target)] << endl;
    return 0;
}