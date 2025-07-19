#include<iostream>
using namespace std;

void update(int &i){
    i++;
}

int main(){
    int i =5;
    // int &j = i;

    cout << i << endl;
    update(i);
    cout << i << endl;
    // cout << j << endl;
    return 0;
}