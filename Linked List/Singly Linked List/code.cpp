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
void insertAtHead(Node* &head, int data){
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data){
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data){

    if (position == 1){
        insertAtHead(head, data);
        return;
    }

    Node *temp = head;
    int count = 1;

    while (count < position - 1){
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL){
        insertAtTail(tail, data);
        return;
    }

    // Creating a new node for insertion
    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
    
}

void deleteAtPosition(Node* &head, int position, Node* &tail){
    if (position == 1){
        // Create new node
        Node *temp = head;
        head = head->next;
        // Removing the pointer
        temp->next = NULL;
        // Memory free of starting node
        delete head;
    }else{
        // DELETING MIDDLE NODE OR LAST NODE
        Node *curr = head;
        Node *prev = NULL;

        int count = 1;

        // Apna current pointer hum position tak le aaye
        while (count < position){
            prev = curr;
            curr = curr->next;
            count++;
        }
        // Deletion wala part
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

        // Updating tail
        if (prev->next == NULL){
            tail = prev;
        }
    }
}

void print(Node* &head){
    Node *temp = head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    } cout << endl;
}

int main(){ 
    Node *node1 = new Node(10);

    // Head pointing to node 1;
    Node *head = node1;
    // Tail pointing to last node;
    Node *tail = node1;


    insertAtTail(tail, 30);
    insertAtPosition(head,tail, 2, 20);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    insertAtPosition(head,tail, 6, 60);
    print(head);

    deleteAtPosition(head, 6, tail);
    print(head);
    cout << "Head is: " << head->data << endl;
    cout << "Tail is: " << tail->data << endl;

    return 0;
}