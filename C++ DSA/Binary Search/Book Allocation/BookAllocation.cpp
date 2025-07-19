#include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid){
    int studentCount = 1;
    int pageSum = 0;
    for (int i = 0 ; i < n ; i++){
        if (pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }else{
            studentCount++;
            if (studentCount > m || arr[i] > mid){
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int main(){
    int arr[] = {10,20,30,40};
    int n = sizeof(arr)/sizeof(int);
    int m = 2;
    int start = 0;
    int arraySum = 0;
    for (int i = 0 ; i < n ; i++){
        arraySum += arr[i];
    }
    int end = arraySum;
    int ans = -1;
    while (start <= end){
        int mid = start + (end - start)/2;
        if(isPossible(arr,n,m,mid)){
            ans = mid;
            end = mid - 1;
        } else{
            start = mid + 1;
        }
    }
    cout << "The answer is : " << ans << endl;
    return 0;
}