#include<iostream>
using namespace std;
int expo(int base, int exp, int mod){
    int res = 1;
    base = base % mod;
    while (exp > 0){
        if (exp & 1){
            res = (1LL * res * base) % mod;
        }
        base = (1LL * base * base);
        exp >>= 1;
    }
    return res;
}
int main(){
    // return base ^ exp modulo m
    int base;
    int exp;
    int mod;
    cin >> base >> exp >> mod;
    int ans = expo(base,exp,mod);
    cout << ans;
    return 0;
}