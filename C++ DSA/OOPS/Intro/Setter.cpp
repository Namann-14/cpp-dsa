#include<iostream>
using namespace std;

class Student{
    private:
        string Name;
        int Age;
        float Marks;
        char Grade;
    public:
        void setObject(string s, int a, float m, char g){
            Name = s;
            Age = a;
            Marks = m;
            Grade = g;
        }
        void display(){
            cout << "Name: " << Name << endl;
            cout << "Age: "<< Age << endl;
            cout << "Marks: "<< Marks << endl;
            cout << "Grade: "<< Grade << endl;
        }
};

int main(){
    Student s1;
    s1.setObject("Naman", 19, 86.69, 'O');
    s1.display();

    return 0;
}