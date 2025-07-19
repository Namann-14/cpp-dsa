#include<iostream>
using namespace std;

class Student{
    public:
        string Name;
        int Age;
        char Grade;
    Student(){
        cout << "Constructor is called" << endl;
    }
};

int main(){
    Student s;
    return 0;
}