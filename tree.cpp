#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void preorder(Node *root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postore(Node *root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    inorder(root->right);
    cout << root->data << " ";
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Pre-order: ";
    preorder(root);
    cout << endl;

    cout << "In-order: ";
    inorder(root);
    cout << endl;

    cout << "Post-order: ";
    postorder(root);
    cout << endl;

    return 0;
}