#include<iostream>
using namespace std;
int main(){
    int arr[3][4] = {{1,2,3,4},{4,5,6,7},{8,9,10,11}};
    int maxi = -1;
    for (int i = 0 ; i < 4; i++){
        int sum = 0;
        for (int j = 0 ; j < 3; j++){
            sum += arr[j][i];
        }
        maxi = max(maxi, sum);
    }
    cout << maxi;
    return 0;
}