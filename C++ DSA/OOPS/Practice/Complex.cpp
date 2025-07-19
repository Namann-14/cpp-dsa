#include<iostream>
using namespace std;

class Complex{
    private:
        int real;
        int img;
    public:
        Complex(){

        }
        Complex(int real, int img){
            this -> real = real;
            this -> img = img;
        }
        Complex operator+(Complex &c){
            Complex ans;
            ans.real = real + c.real;
            ans.img = img + c.img;
            return ans;
        }
        void display(){
            cout << real << '+' << img << endl;
        }
};

int main(){
    Complex c1(1,2);
    Complex c2(3,4);
    Complex c3 = c1 + c2;
    c3.display();

    return 0;
}