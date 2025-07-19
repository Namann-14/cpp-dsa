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

        Student(string n, int a, char g) {
            Name = n;
            Age = a;
            Grade = g;
            cout << "Parameterized constructor is called" << endl;
        }
};

int main() {
    Student s1; // Calls the default constructor
    Student s2("Naman Nayak", 19, 'O'); // Calls the parameterized constructor
    return 0;
}
