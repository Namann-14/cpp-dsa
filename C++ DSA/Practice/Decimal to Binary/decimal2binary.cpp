#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cout << "Enter the value of n: ";
    cin>> n;
    int i = 0;
    int bin = 0, place = 1;

    // METHOD 1 
    while (n){
        int bit = n % 2;
        bin = bit * pow(10,i) + bin;
        n /= 2;
        i++;
    }
    cout << "The binary for " << n << " is: " << bin << endl;
    return 0;

    // METHOD 2
    // while (n){
    //     bin = bin + (n & 1) * place; 
    //     n = n >> 1;
    //     place *= 10;
    // }
    // cout << "The binary for " << n << " is: " << bin << endl;
    return 0;
}