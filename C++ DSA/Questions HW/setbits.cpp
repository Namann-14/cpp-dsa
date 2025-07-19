#include<iostream>
using namespace std;
int count(int n){
    int cnt = 0;
    while (n != 0){
        int binary = n & 1;
        n = n >> 1;
        if (binary == 1){
            cnt++;
        }
    }
    return cnt;
}
int main(){
    int a,b;
    cout << "Enter the value of a and b: ";
    cin >> a >> b;
    int ans = count(a) + count (b);
    cout << "no of set bits are : " << ans ;
    return 0;
}