#include<iostream>
using namespace std;

class Student{
    public:
        string Name;
        int Age;
        char Grade;
};

int main(){
    Student *s = new Student;
    (*s).Name = "Naman Nayak";
    s->Age = 19;
    s->Grade = 'O';
    cout << "Name: " << s->Name << endl;
    cout << "Age: "<< s->Age << endl;
    cout << "Grade: "<< s->Grade << endl;
    return 0;
}