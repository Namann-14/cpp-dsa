#include<iostream>
using namespace std;
int main(){
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int target;
    cin >> target;
    // time complexcity O(n*n);
    for (int i = 0 ; i < 3; i++){
        for (int j = 0 ; j < 3; j++){
            if (arr[i][j]==target){
                cout << "Found";
            }
        }
    }
    return 0;
}