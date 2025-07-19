#include<iostream>
using namespace std;

class Student{
    public:
        string Name;
        int Age;
        float Marks;
        char Grade;
};

int main(){
    Student s1;
    s1.Name = "Naman Nayak";
    s1.Age = 19;
    s1.Marks = 86;
    s1.Grade = 'O';

    cout << "Name: " << s1.Name << endl;
    cout << "Age: "<< s1.Age << endl;
    cout << "Marks: "<< s1.Marks << endl;
    cout << "Grade: "<< s1.Grade << endl;
    return 0;
}