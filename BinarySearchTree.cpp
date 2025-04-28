#include <iostream>

using namespace std;

class Node
{
public:
    int key;
    Node *leftChild;
    Node *rightChild;

    Node(int key) : leftChild(nullptr), rightChild(nullptr), key(key) {}
};

class BST
{
public:
    Node *root;

    BST() : root(nullptr) {}

    void insert(int value)
    {
        root = insertRecursive(root, value);
    }

    bool search(int value)
    {
        return searchRecursive(root, value);
    }

    void deleteNode(int value)
    {
        root = deleteRecursively(root, value);
    }

    void InOrderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            InOrderTraversal(node->leftChild);
            cout << node->key << " ";
            InOrderTraversal(node->rightChild);
        }
    }

private:
    Node *insertRecursive(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }

        if (value <= node->key) // left biased as equals sign is used
        {
            node->leftChild = insertRecursive(node->leftChild, value);
        }
        else
        {
            node->rightChild = insertRecursive(node->rightChild, value);
        }
        return node;
    }

    bool searchRecursive(Node *node, int key)
    {
        if (node == nullptr)
            return false;

        if (node->key == key)
            return true;

        if (key < node->key)
        {
            return searchRecursive(node->leftChild, key);
        }
        else
        {
            return searchRecursive(node->rightChild, key);
        }
    }

    Node *deleteRecursively(Node *node, int key)
    {
        if (node == nullptr)
            return node;

        // Traverse the tree to find the node to delete
        if (key < node->key)
        {
            node->leftChild = deleteRecursively(node->leftChild, key); // Move leftChild if key is smaller
        }
        else if (key > node->key)
        {
            node->rightChild = deleteRecursively(node->rightChild, key); // Move rightChild if key is larger
        }
        else
        {
            // We found the node to delete
            if (node->leftChild == nullptr && node->rightChild == nullptr)
            {
                // Case 1: Node has no children (it's a leaf node)
                delete node;
                node = nullptr;
            }
            else if (node->leftChild == nullptr)
            {
                // Case 2: Node has only a right child
                Node *temp = node;
                node = node->rightChild;
                delete temp;
            }
            else if (node->rightChild == nullptr)
            {
                // Case 2: Node has only a left child
                Node *temp = node;
                node = node->leftChild;
                delete temp;
            }
            else
            {
                // Case 3: Node has two children
                // Find the largest node in the left subtree (inorder predecessor)
                Node *temp = findMax(node->leftChild);
                // Copy the inorder predecessor's content to this node
                node->key = temp->key;
                // Delete the inorder predecessor
                node->leftChild = deleteRecursively(node->leftChild, temp->key);
            }
        }

        return node; // Return the modified tree root
    }

    // Function to find the maximum value node in a subtree
    Node *findMax(Node *node)
    {
        while (node->rightChild != nullptr)
            node = node->rightChild;
        return node;
    }
};

int main()
{
    BST bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(1);
    bst.insert(2);
    bst.insert(20);
    bst.insert(15);
    bst.insert(30);
    bst.deleteNode(1);
    bst.InOrderTraversal(bst.root);
    string ans = bst.search(2) ? "Found" : "Not Found";
    cout << endl
         << ans;
    return 0;
}