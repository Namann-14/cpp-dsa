// finding pivot element in a sorted rotated array 
#include<iostream>
using namespace std;
int main(){
    int arr[] = {7,9,1,2,3};
    int s = 0;
    int e = sizeof(arr)/sizeof(int) - 1 ;
    int mid;
    while (s<e){
        mid = s + (e-s)/2;
        if (arr[mid] >= arr[0]){
            s = mid + 1;
        }else{
            e = mid;
        }
    }
    cout << "Pivot element is : " << arr[s];
    return 0;
}