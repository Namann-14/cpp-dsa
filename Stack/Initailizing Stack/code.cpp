#include<iostream>
using namespace std;

class Stack
{
private:
    int top;
    int *arr;
    int size;
public:
    Stack(int size){
        this->size = size;
        top = -1;
        arr = new int[size];
    }
    void push(int data){
        if (size - top > 1){
            top++;
            arr[top] = data;
            return;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }
    void pop(){
        if (top >= 0){
            top--;
        }else{
            cout << "Stack underflow" << endl;
        }
    }

    int peek() {
        if (top >= 0 && top < size){
            return arr[top];
        }else{
            cout << "Stack is empty" << endl;
        }
    }

    bool isEmpty(){
        return (top < 0);
    }
};
int main(){
    Stack* s = new Stack(5);
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    s->push(5);
    s->pop();
    cout << s->peek();
    return 0;
}