#include<iostream>
using namespace std;

class Student {
    public:
        string Name;
        int Age;
        char Grade;

        Student() {
            cout << "Default constructor is called" << endl;
        }

        Student(string Name, int Age, char Grade) {
            this->Name = Name;
            this->Age = Age;
            this->Grade = Grade;
        }

        void display(){
            cout << "Name: " << Name << endl;
            cout << "Age: " << Age << endl;
            cout << "Grade: " << Grade << endl;
        }

        // copy constructor user defined
        Student(Student &b){
            Name = b.Name;
            Age = b.Age;
            Grade = b.Grade;
        }
};

int main() {
    Student s1("Naman Nayak", 19, 'O');
    s1.display();

    // Default copy constructor
    Student s2(s1);
    s2.display();    

    Student s3;
    s3 = s1;
    s3.display();
    return 0;
}
