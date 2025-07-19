#include<iostream>
#include<vector>
using namespace std;

class Animal{
    public:
        virtual void speak() = 0; // Abstract class
};

class Dog : public Animal {
    public:
        void speak(){
            cout<< "Bark" << endl;
        }
};

class Cat : public Animal {
    public:
        void speak(){
            cout<< "Meow" << endl;
        }
};

int main(){
    // p = new Dog();
    // p->speak();

    Animal *p;
    vector<Animal*>anime;
    anime.push_back(new Dog());
    anime.push_back(new Cat());
    anime.push_back(new Cat());
    anime.push_back(new Dog());

    for (int i = 0; i < anime.size(); i++){
        p = anime[i];
        p->speak();
    }
    return 0;
}