#include<iostream>
using namespace std;
int hcf (int a, int b){
    if (a==0) return b;
    if (b==0) return a;

    while (a != b){
        if (a > b){
            a -= b;
        }else{
            b -= a;
        }
    }
    return a;
}
int main(){
    int a,b;
    cin >> a >> b;
    cout << hcf(a,b);
    return 0;
}