#include<iostream>
using namespace std;

class Complex{
    public:
        int real;
        int img;
        Complex(){};
        Complex(int real, int img){
            this -> real = real;
            this -> img = img;
        }
        Complex operator+(Complex &other){
            return Complex(real + other.real, img + other.img);
        }

        Complex operator*(Complex &other){
            return Complex(real * other.real - img * other.img , real * other.img + img * other.real);
        }
        void display(){
            cout << "Real: " << real << "Img: " << img << endl;
        }
};

int main(){
    Complex c1(5,7);
    Complex c2(1,9);
    Complex c3 = c1 + c2;
    c3.display();
    Complex c4 = c1 * c2;
    c4.display();
    return 0;
}