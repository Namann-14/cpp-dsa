#include<iostream>
using namespace std;

class Hero{
    private:
    int health;
    string name;
    public:
    // Default constructor
    Hero(){
        cout << "Default constructor called" << endl;
    }
    // Parameterized constructor 
    Hero(int health){
        this-> health = health;
    }

    // Constructor overloading
    Hero(int health, string name){
        this-> health = health;
        this-> name = name;
        print();
    }

    // Copy constructor
    Hero(Hero& temp){
        this -> name = temp.name;
        this -> health = temp.health;
    }

    void print(){
        cout << "Name is: " << this-> name << endl;
        cout << "Health is: " << this-> health << endl;
    }
    string getName() const{
        return this->name;
    }
    int getHealth() const{
        return this->health;
    }
    void setName(const string name){
        this->name = name;
    }
    void setHealth(const int h){
        this->health = h;
    }

    ~Hero(){
        cout << "Destructor called" << endl;
    }
};
int main(){
    const int x = 5;
    // x = x + 1; error



    Hero h5;
    Hero *h6 = new Hero;
    delete h6;




    // Static allocation
    // Hero h1;

    // Dynamic allocation
    // Hero *h2 = new Hero;
    // h2->setName("Naman");
    // h2->setHealth(19);
    // cout << h2->getName() << endl;
    // cout << h2->getHealth()  << endl;

    // Hero h3(50, "Kritika");
    // Hero h4 (h3);
    // cout << h4.getName();


    /*
    cout << sizeof(h1) << endl;
    h1.health = 56;
    cout << h1.health;
    */
    return 0;
}