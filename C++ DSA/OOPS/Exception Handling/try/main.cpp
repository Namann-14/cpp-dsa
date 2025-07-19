#include<iostream>
using namespace std;

class Customer{
    private:
        string Name;
        int Balance, accountNumber;
    public:

        Customer(string Name, int Balance, int accountNumber){
            this->Name = Name;
            this->Balance = Balance;
            this->accountNumber = accountNumber;
            displayBalance();
        }

        void displayBalance(){
            cout << "Balance: " << Balance << endl;
        }

        void deposit(int n){
            if (n >= 0){
                Balance += n;
            }else{
                throw "Low deposit";
            }
        }

};

int main(){
    Customer c1("Naman", 100, 123);
    try{
    c1.deposit(500);
    c1.displayBalance();
    }catch(const char *e){
        cout << "Exception Occured: " << e << endl;
    }
    return 0;
}
