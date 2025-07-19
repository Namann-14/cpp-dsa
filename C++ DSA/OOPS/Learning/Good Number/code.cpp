#include <iostream>
#include <vector>
#include<cmath>
using namespace std;

bool isPrime(int n){
    if (n==1) return false;
    if (n==2) return true;
    for (int i = 2 ; i < sqrt(n); i++){
        if (n%i==0){
            return false;
        }
    }
    return true;
}

bool numCheck(int n){
    bool flag = true;

    int digit = n%10;
    if (!isPrime(digit)){
        flag = false;
    }
    n /=10;
    return flag;
}

int goodNumber(vector<int>arr){
    int count = 0;
    for (int i = 0 ;i < arr.size(); i++){
        if (isPrime(arr[i]) && numCheck(arr[i])){
            count++;
        }  
    }
    return count;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;  

    vector<int> arr(n);  

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  
    }

    cout << goodNumber(arr);

    return 0;
}
