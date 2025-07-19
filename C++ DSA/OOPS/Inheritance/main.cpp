#include<iostream>
using namespace std;
class Human{
    private:
        string Race;
        int Age;
    protected:
        string Name;
        char Grade;
        float Marks;
    public:
        string University;
        Human(){
        cout << "Default constructor called " << endl;
        }

        Human(string Name, char Grade, float Marks){
            this->Name = Name;
            this-> Grade = Grade;
            this->Marks = Marks;
        }
};

class Student : public Human{
    private:
        bool inLove;
    public:
    Student(){
        cout << "Default constructor called " << endl;
    }
    Student(string Name, char Grade, float Marks, bool inLove):Human(Name,Grade,Marks){
        this -> inLove = inLove;
    }

    void display(){
        cout << "Name: " << Name << endl;
        cout << "Grade: " << Grade << endl;
        cout << "Marks: " << Marks << endl;
        cout << "University: " << University << endl;
        cout << "In love: " << inLove << endl;
    }
    
};

int main(){
    Student s1("Naman", 'O', 69, true);
    s1.University = "Chitkara";
    s1.display();
    return 0;
}