#include<iostream>
using namespace std;

int Sqrt(int n, int start, int end){
    if (start > end){
        return 0;
    }
    int mid = start + (end - start)/2;

    if (mid * mid == n){
        return mid;
    }
    if (mid * mid > n){
        return Sqrt(n, start, mid - 1);
    }else{
        return Sqrt(n, mid + 1, end);
    }
}

int main(){
    int n;
    cin >> n;
    int start = 0;
    int end = n;
    cout << "The sqrt of " << n << " is: " << Sqrt(n, start, end) << endl;
    return 0;
}