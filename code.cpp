#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *parent;
    Node *left;
    Node *right;
    Node(int k) {
        key = k;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }
};

void inOrderWithDepth(Node *node, int depth) {
    if (node == nullptr) {
        return;
    }
    inOrderWithDepth(node->left, depth + 1);
    cout << depth << ": " << node->key << endl;
    inOrderWithDepth(node->right, depth + 1);
}

int main() {
    // Build the tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    // Optional: set parent pointers if needed
    root->left->parent = root;
    root->right->parent = root;
    root->left->left->parent = root->left;
    root->left->right->parent = root->left;
    root->right->right->parent = root->right;

    // Test the function
    inOrderWithDepth(root, 0);

    return 0;
}