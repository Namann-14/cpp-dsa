#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    // Constructor 
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node(){
        int value = this->data;
        if (this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }   
};

void insertNode(Node* &tail, int element, int data){
    // Assuming element is present in the list

    // If list is empty
    if (tail == NULL){
        Node *temp = new Node(data);
        temp->next = temp;
        tail = temp;
    }else{
        Node *curr = tail;

        while (curr->data != element){
            curr = curr->next;
        }
        
        // Current found
        Node *temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;

    }
}

void deleteNode(Node* &tail, int postion){
    
}

void print(Node* tail){
    Node *temp = tail;
    do {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

int main(){ 
    Node *tail = NULL;
    insertNode(tail, 5, 3);
    insertNode(tail, 3, 5);
    insertNode(tail, 5, 7);
    print(tail);
    return 0;
}