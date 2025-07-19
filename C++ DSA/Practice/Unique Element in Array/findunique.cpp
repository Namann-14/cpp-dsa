#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,2,3,1,2,4,4};
    int size = sizeof(arr)/sizeof(int);
    int ans = 0;
    for (int i = 0 ; i < size ; i++ ){
        ans = ans ^ arr[i];
    }
    cout << "Real answer" << ans << endl;
    return 0;
}