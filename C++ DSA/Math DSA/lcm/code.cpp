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
    int a ,b;
    cin >> a >> b;
    // a * b = hcf(a,b) * lcm (a,b);
    int lcm = (a*b)/hcf(a,b);
    cout << lcm;
    return 0;
}