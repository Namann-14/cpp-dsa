#include<iostream>
using namespace std;

int main() {
    try {
        int *p = new int[10000000000000];
        cout << "Memory is allocated";
        delete[] p;
    } 
    catch (const bad_alloc &e) { 
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}
