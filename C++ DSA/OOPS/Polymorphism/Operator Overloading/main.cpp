#include<iostream>
using namespace std;

class Complex{
    private:
        int Real;
        int Img;
    public:
        Complex(){
            cout << "Default constructor called" << endl;
        };
        Complex(int Real, int Img){
            this -> Real = Real;
            this -> Img = Img;
            display();
        }
        void display(){
            cout << "Real: " << Real << " " << "Imaginary: " << Img << endl;
        }

        Complex operator+(Complex &c){
            Complex ans;
            ans.Real = Real + c.Real;
            ans.Img = Img + c.Img;
            return ans;
        }
};

int main(){
    Complex c1(5,6);
    Complex c2(5,4);

    Complex c3 = c1 + c2;
    c3.display(); 
    return 0;
}