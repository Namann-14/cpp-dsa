#include<iostream>
using namespace std;
int fact (int n){
    if (n == 0) return 1;
    return n*fact(n-1);
}
int nCr (int n, int r){
    if (n>=r){
    int ans = fact (n) / ( fact(r) * fact(n-r));
    return ans;
    }
    else {
        return 0;
    }
}
int main(){
    int n,r;
    cout << "Enter the value of n and r" ;
    cin >> n;
    cin >> r;
    cout << "The value of ncr = " << nCr(n,r);
    return 0;
}