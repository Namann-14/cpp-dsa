#include<iostream>
using namespace std;

class Customer
{
private:
    string name;
    int balance;
    bool isSavings;
    static int count;
    static int totalBalance;
public:
    Customer(string name, int bal, bool isSavings){
        this ->name = name;
        this ->balance = bal;
        this ->isSavings = isSavings;
        count++;
        totalBalance+=balance;
    };

    static void displayStatic(){
        cout << "Total customer is: " << count << endl;
        cout << "Total Balance  is: " << totalBalance << endl;
    }

    void display(){
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
        cout << "Savings: " << isSavings << endl;
    }
};

int Customer::count = 0;
int Customer::totalBalance = 0;

int main(){
    Customer c1("Naman",100, true);
    c1.display();
    Customer c2("Kritika",200, true);
    c2.display();
    Customer c3("Hardik",300, false);
    c3.display();

    Customer::displayStatic();

    return 0;
}