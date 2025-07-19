#include<iostream>
using namespace std;

void count(int n){
    // Base Case 
    if (n == 0){
        return;
    }
    // Processing 
    cout << n << endl;

    // Reccuronce Relation
    count(n-1);
}

void print(int n){
    //  Base Case
    if (n==0){
        return;
    }
    // Reccuronce Relation
    print (n -1);

    // Processing
    cout << n << endl;

}

int main(){
    int n;
    cin >> n;
    cout << endl << endl;
    // count(n);
    print(n);
    return 0;
}