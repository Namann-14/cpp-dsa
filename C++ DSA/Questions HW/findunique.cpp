#include<iostream>
using namespace std;
int findUnique(int arr[], int len){
    int ans = 0;
    for (int i = 0 ; i < len ; i++){
        ans = ans ^ arr[i];
    }
    return ans;
}
int main(){
    int arr[] = {3,1,4,3,1};
    int len = sizeof(arr)/sizeof(int);
    cout << "unique element is : " << findUnique(arr,len);
    return 0;
}