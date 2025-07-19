#include <bits/stdc++.h>
using namespace std;

class Node{
    public:    
        int data;
        Node* left;
        Node* right;
        Node(int data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};

Node* BuildTree(Node* root) {
    cout << "Enter the value of the root: ";
    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1) {
        return nullptr;
    }

    cout << "Enter the value of left side of " << data << ": ";
    root->left = BuildTree(root->left);
    cout << "Enter the value to right side of " << data << ": ";
    root->right = BuildTree(root->right);

    return root;
}

void Inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Preorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(Node* root) {
    if (root == nullptr) {
        cout << "The tree is empty"<<  endl;
        return;
    }
    queue<Node*>q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp == nullptr) {
            cout << endl;
            if (!q.empty()){
                q.push(nullptr);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void levelOrderBuild(Node* &root) {
    int data;
    cout << "Enter the value of root Node: ";
    cin >> data;
    
    if (data == -1) {
        return;
    }

    root = new Node(data);

    queue<Node*>q;
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        int leftData;
        cout << "Enter the value of leftData for node" << temp->data << ": ";
        cin >> leftData;
        if (leftData != -1) {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }
        int rightData;
        cout << "Enter the value of rightData for node " << temp->data << ": " << endl;
        cin >> rightData;
        if (rightData != -1) {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

int main() {
    Node* root = NULL;
    
    levelOrderBuild(root);
    levelOrderTraversal(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    // // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // root = BuildTree(root);
    // levelOrderTraversal(root);
    // cout << "Inorder: "; inorder(root);
    // cout << endl;
    // cout << "Preorder: "; preorder(root);
    // cout << endl;
    // cout << "Postorder: "; postorder(root);
    return 0;
}