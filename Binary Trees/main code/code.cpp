#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* BuildTree(Node* root) {
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);


    if (data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = BuildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = BuildTree(root->right);
    return root;
    
    return root;
}

void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty" << endl;
        return;
    }

    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            // Current level completed
            cout << endl;  // Move to next line for next level
            if (!q.empty()) {
                // some elements are still left
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";  // Print node value with space
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node* root) {
    if (!root) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelOrderBuild(Node* &root) {
    int data;
    cout << "Enter value of root Node: ";
    cin >> data;
    
    if (data == -1) {
        return;
    }

    root = new Node(data);
    
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter the value of leftData for node " << temp->data << ": " << endl;
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
int main(){
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