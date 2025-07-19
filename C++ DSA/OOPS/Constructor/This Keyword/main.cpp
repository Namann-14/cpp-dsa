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
            cout << "Parameterized constructor is called" << endl;
        }

        // Constructor overloading
        Student(string Name, int Age){
            this -> Name = Name;
            this -> Age = Age;
        }

        float Marks;
        // inline Constructor
        inline Student (string Name, int Age, char g ,float Marks ): Name(Name), Age(Age), Marks(Marks), Grade(g){

        }

        void display(){
            cout << Name << endl;
            cout << Age << endl;
            cout << Grade << endl;
            cout << Marks << endl;
        }

};

int main() {
    // Calls the default constructor
    Student s1;

    // Calls the parameterized constructor
    Student s2("Naman Nayak", 19, 'O'); 
    s2.display();

    // Calls the 2nd parameterized constructor
    Student s3("Naman Nayak", 19);
    s3.display();

    Student s4("Naman Nayak", 19, 'O', 86.69);
    s4.display();

    return 0;
}
