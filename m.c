#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    // Constructor
    Node(int value) {
        key = value;
        left = right = nullptr;
        height = 1;  // Initial height of a new node
    }
};

class AVLTree {
public:
    // Function to get the height of a node
    int getHeight(Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    // Function to calculate balance factor of a node
    int getBalance(Node* node) {
        if (node == nullptr) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    // Right rotation for balancing
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;  // New root
    }

    // Left rotation for balancing
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;  // New root
    }

    // Insert function for AVL Tree
    Node* insert(Node* node, int key) {
        // 1. Perform the normal BST insertion
        if (node == nullptr) {
            return new Node(key);
        }
        
        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        } else {
            // Equal keys are not allowed in AVL Tree
            return node;
        }

        // 2. Update the height of this ancestor node
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // 3. Get the balance factor of this ancestor node
        int balance = getBalance(node);

        // 4. Perform rotations if the node becomes unbalanced

        // Left Left Case
        if (balance > 1 && key < node->left->key) {
            return rotateRight(node);
        }

        // Right Right Case
        if (balance < -1 && key > node->right->key) {
            return rotateLeft(node);
        }

        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        // Return the (unchanged) node pointer
        return node;
    }

    // Inorder traversal of the AVL tree
    void inorderTraversal(Node* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << root->key << " ";
            inorderTraversal(root->right);
        }
    }
};

// Main function to test the AVL Tree
int main() {
    AVLTree tree;
    Node* root = nullptr;

    // Inserting nodes into the AVL Tree
    root = tree.insert(root, 10);
    root = tree.insert(root, 20);
    root = tree.insert(root, 30);
    root = tree.insert(root, 40);
    root = tree.insert(root, 50);
    root = tree.insert(root, 25);

    cout << "Inorder traversal of the AVL Tree: ";
    tree.inorderTraversal(root);

    return 0;
}
