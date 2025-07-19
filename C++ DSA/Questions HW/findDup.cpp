// given array of of size n.. the elements are 1 - n-1 come atleast once..  the last element is duplicate. find dup
#include<iostream>
using namespace std;
int main(){
    int arr[] = {2,4,1,3,1};

    // method 1 XOR
    // int ans = 0;
    // for (int i = 0 ; i < 5 ; i++){
    //     ans = ans ^ arr[i];
    // }
    // for (int i = 0 ; i < 5 ; i++){
    //     ans = ans ^ i;
    // }
    // cout << ans<<endl;
    // return 0;

    // method 2 BRUTE FORCE
    int dup;
    for (int i = 0 ; i < 5 ; i++){
        for (int j = i+1 ; j < 5 ; j++){
            if (arr[i] == arr[j]){
                dup = arr[i];
                break;
            }
        }
    }
    cout << dup ;
}


    //     vector<int> fans;
    //     int ans = 0;
    //    for (int i = 0 ; i < nums.size() ; i++){
    //     ans = ans ^ nums[i];
    //    } 
    //    for (int i = 0 ; i < nums.size() ; i++){
    //     ans = ans ^ i;
    //    }
    //     fans.push_back(ans);
    //     return fans;

    