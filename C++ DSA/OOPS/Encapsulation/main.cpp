#include <iostream>
using namespace std;

class Student {
private:
    string Name;
    int Age;
    char Grade;

public:
    Student(string Name, int Age, char Grade) {
        if (Name.size() > 0) {
            this->Name = Name;
        } else {
            displayError();
            this->Name = "Unknown"; // Assign a default value
        }
        this->Age = Age;
        this->Grade = Grade;
    }

    void displayError() const {
        cout << "Error: Name cannot be empty." << endl;
    }

    void displayInfo() const {
        cout << "Name: " << Name << ", Age: " << Age << ", Grade: " << Grade << endl;
    }
};

int main() {
    Student student1("John", 20, 'A');
    student1.displayInfo();

    Student student2("", 18, 'B'); // Will trigger the error message
    student2.displayInfo();

    return 0;
}
