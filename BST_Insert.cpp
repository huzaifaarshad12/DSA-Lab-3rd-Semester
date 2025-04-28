#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) {
        key = value;
        left = right = nullptr;
    }
};

// Function to insert a new node with given key in the BST
Node* insert(Node* root, int key) {
    // If the tree is empty, return a new node
    if (root == nullptr) {
        return new Node(key);
    }

    // Otherwise, recur down the tree
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    // Return the unchanged root pointer
    return root;
}

// Inorder traversal of the BST (to check if elements are inserted correctly)
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

// Main function
int main() {
    Node* root = nullptr;

    // Inserting nodes into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder traversal of the BST: ";
    inorderTraversal(root);

    return 0;
}
