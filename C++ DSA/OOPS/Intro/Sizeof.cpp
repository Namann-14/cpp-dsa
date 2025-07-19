#include<iostream>
using namespace std;
class Student {
    public:
        // double e;
        // float d;
        // int a;
        // char b;
        // char c;
        string Name;
};

int main(){
    Student s1;
    cout << sizeof(s1) << endl;
    return 0;
}