#include<iostream>
using namespace std;

class Employee{
    protected:
        int id;
        string name;
        double baseSalary;
    public:
        Employee(int id, string name, double baseSalary) : id(id), name(name), baseSalary(baseSalary){};
        Employee(){};
        virtual double calculateSalary() = 0;
        void printEmployee(){
            cout << "Id: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Base Salary: " << baseSalary << endl;
            cout << "New Salary: " << calculateSalary() << endl;
        }
        ~Employee(){};
};

class Engineer : public Employee{
    private:
        int projectCompleted;
    public:
        Engineer(int id, string salary, double baseSalary, int projectCompleted ) : Employee(id, salary, baseSalary), projectCompleted(projectCompleted){};
        double calculateSalary() override{
            return baseSalary + (500 * projectCompleted);
        }
};

class Manager : public Employee{
    private:
        int teamManaged;
    public:
        Manager(int id, string salary, double baseSalary, int teamManaged ) : Employee(id, salary, baseSalary), teamManaged(teamManaged){};
        double calculateSalary() override{
            return baseSalary * (2500 * teamManaged);
        }
};

int main(){
    int n;
    cin >> n;
    Employee* worker[n];
    for (int i = 0 ; i < n ; i++){
        char type;
        int id;
        string name;
        double baseSalary;
        cin >> type >> id >> name >> baseSalary;
        if (type == 'E'){
            int projectCompleted;
            cin >> projectCompleted;
            worker[i] = new Engineer(id,name,baseSalary,projectCompleted);
        }else{
            int teamManaged;
            cin >> teamManaged;
            worker[i] = new Manager(id, name, baseSalary, teamManaged);
        }
    }
    for (int i = 0 ; i < n ; i++){
        worker[i]->printEmployee();
        delete worker[i];
    }
    return 0;
}