#include <iostream>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
    int height;


    Node(int value){
        key = value;
        left = right = nullptr;
        height = 1;
    }
}
class AVLTree{
    public: 
    int getheight(Node* node){
        if(node == nullptr){
            return 0;
        }
        return node->height;
    }
    int getbalanceFactor(Node* node){
        if(node == nullptr){
            return 0;
        }
        return getheight(node->left)- getheight(node->right);
    }
    Node* RightRotation(Node* y){
        Node* x = y->left;
        Node* T2 = x->right;


        x->right = y
        y->left = T2

        y->height = max(getheight(y->left), getheight(y->right))+ 1 ;
        -x>height = max(getheight(x->left), getheight(x->right))+ 1 ;

        return x;


    }
    Node* LeftRotation(Node* x){
        Node* y = x->right;
        Node* T2 = y->left;


        y->left = x
        x->right = T2

        y->height = max(getheight(y->left), getheight(y->right))+ 1 ;
        x->height = max(getheight(x->left), getheight(x->right))+ 1 ;

        return y;


    }
    Node* insert(Node* node , int key){
        if(node == nullptr){
            return new Node(key);
        }
        if(key <Node->key){
            node->left = insert(Node->left, key)

        }
        else if()
    }
}

