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

void inorderWithDepth(Node *node, int depth) {
    if (node == nullptr) {
        return;
    }
    inorderWithDepth(node->left, depth + 1);
    cout << depth << ": " << node->key << endl;
    inorderWithDepth(node->right, depth + 1);
}

Node *addToBST(Node *node, int k) {
    if (node == nullptr) {
        return new Node(k);
    }
    if (k < node->key) {
        node->left = addToBST(node->left, k);
        if (node->left) {
            node->left->parent = node;
        }
    } else {
        node->right = addToBST(node->right, k);
        if (node->right) {
            node->right->parent = node;
        }
    }
    return node;
}

Node* search(Node*root, int key) {
    if (root == nullptr || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

int main() {
    Node* root = nullptr;

    // Insert some values
    root = addToBST(root, 10);
    root = addToBST(root, 5);
    root = addToBST(root, 15);
    root = addToBST(root, 2);
    root = addToBST(root, 7);
    root = addToBST(root, 20);

    // Print inorder with depth
    inorderWithDepth(root, 0);

    return 0;
}