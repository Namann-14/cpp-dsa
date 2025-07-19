#include<iostream>
using namespace std;

int fact(int n){
    // Base Case
    if (n ==0){
        return 1;
    }
    
    // Processing
    // cout << n << endl;

    // Recurrence Relation
    return n * fact(n-1);
}

int main(){
    int n;
    cin >> n;
    // Function calling
    cout << fact(n);
    return 0;
}