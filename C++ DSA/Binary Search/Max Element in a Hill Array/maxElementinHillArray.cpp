#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,7,5,3,2,1};
    int s = 0;
    int e = sizeof(arr)/sizeof(int) -1 ;
    int mid;
    while (s<e){
        mid = s + (e-s)/2;
        if (arr[mid]<arr[mid+1]){
            s = mid + 1;
        }else{
            e = mid;
        }
    }
    cout<< "max element is " << arr[s];
    return 0;
    
}