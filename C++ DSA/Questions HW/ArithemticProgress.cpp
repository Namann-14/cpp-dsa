#include<iostream>
using namespace std;
int ap(int n){
    int ans = 3*n + 7;
    return ans;
}
int main(){
    int n;
    cout << "Enter the value of n";
    cin >> n;
    cout << "The nth term is : " << ap(n);
}