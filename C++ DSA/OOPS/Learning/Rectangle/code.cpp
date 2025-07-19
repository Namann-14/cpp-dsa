#include<iostream>
using namespace std;

class Rectangle{
    private:
        unsigned int length;
        int breath;
    public:
        Rectangle(int length, int breath) : length(length), breath(breath){};
        void area(){
            cout << length * breath;
        }
};

int main(){
    int l,b;
    cin >> l >> b;
    Rectangle r1(l,b);
    r1.area();
    return 0;
}