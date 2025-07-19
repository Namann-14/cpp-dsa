#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data) {
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int val = this->data;
        if (this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << "Memory Freed at postion: " << val << endl;
    }
};

void insertAtHead(Node *&head, int data) {
    Node *temp = new Node(data);
    if (head == NULL) {
        head = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node *&tail, int data) {
    Node *temp = new Node(data);
    if (tail == NULL) {
        tail = temp;
        return;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node *&head, int data, int position, Node *&tail) {
    if (position == 1) {
        insertAtHead(head, data);
        return;
    }

    Node *temp = head;
    int count = 1;

    while (count < position - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL || temp->next == NULL) {
        insertAtTail(tail, data);
        return;
    }

    Node *nodetoInsert = new Node(data);
    nodetoInsert->next = temp->next;
    temp->next->prev = nodetoInsert;

    temp->next = nodetoInsert;
    nodetoInsert->prev = temp;
}

void deleteAtPosition(Node* &head, int position, Node* &tail){
    if (position == 1){
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;    
    }else{
        Node *prev = NULL;
        Node *curr = head;

        int count = 1;
        while (count < position){
            prev = curr;
            curr = curr->next;
            count++;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        if (prev->next == NULL){
            tail = prev;
        }
    }
}

int getLength(Node *&head) {
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void print(Node *&head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node *n1 = new Node(20);
    Node *head = n1;
    Node *tail = n1;

    insertAtHead(head, 10);
    insertAtTail(tail, 30);
    insertAtPosition(head, 40, 4, tail);
    insertAtPosition(head, 50, 5, tail);
    insertAtPosition(head, 60, 6, tail);
    print(head);

    //deleteAtPosition(head, 1);
    //deleteAtPosition(head, 3);
    //deleteAtPosition(head, 4);
    deleteAtPosition(head, 6, tail);

    print(head);

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    cout << "Length of Linked List is: " << getLength(head) << endl;

    return 0;
}
