#include<iostream>
using namespace std;

class Human {
    public:
        string Name;
        int Age;
};

class Engineer : virtual public Human { // Virtual inheritance
    public:
        void displayEn(){
            cout << "I am Engineer" << endl;
        }
};

class Youtuber : virtual public Human { // Virtual inheritance
    public:
        void displayEn(){
            cout << "I am Youtuber" << endl;
        }
};

class CodeTeacher : public Youtuber, public Engineer {
    public:
        CodeTeacher() {
            this->Name = "Naman";
            this->Age = 19;
        }

        void displayInfo() {
            cout << "Name: " << Name << ", Age: " << Age << endl;
        }
};

int main() {
    CodeTeacher c1;
    c1.displayInfo(); 
    return 0;
}
