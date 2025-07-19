#include <iostream>
using namespace std;

class Student {
    public:
        string Name;
        int Age;
        char Grade;
        int *data; // Pointer for dynamic allocation

        // Default constructor
        Student() {
            cout << "Default constructor is called" << endl;
            data = new int; 
            *data = 1000;
        }

        // Parameterized constructor
        Student(string Name) {
            this->Name = Name;
        }

        // Display function
        void display() {
            cout << "Name: " << Name << endl;
            cout << "Address of data: " << data << endl;
            cout << "Value of data: " << *data << endl;
        }

        // Destructor
        ~Student() {
            delete data; // Free dynamically allocated memory
            cout << "Destructor is called, memory freed" << endl;
        }
};

int main() {
    Student s1;
    s1.display();
    return 0;
}
