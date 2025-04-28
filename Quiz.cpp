#include<iostream>
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

};
class AVLTree{
    public: 
        int getheight(Node* node){
            if(node == nullptr)
            {
                return 0;
            }
            return node->height;
        }
        int getBalanceFactor(Node* node){
            if(node == nullptr){
                return 0;
            }
            return getheight(node->left)- getheight(node->right);
        }


        Node* RightRotation(Node* y){
            Node* x = y->left;
            Node* T2 = x->right;

            x-> right = y;
            y->left = T2;

            int x = max(getheight(x->left), getheight(x->right)) + 1;
            int y = max(getheight(y->left), getheight(y->right))+ 1;
            
            return x;
        }

    
        Node* LeftRotation(Node* x){
            Node* y = x->right;
            Node* T2 = y->left;


            y->left = x;
            x->right = T2;

            int x = max(getheight(x-> left), getheight(x -> right))+ 1;
            int y = max(getheight(y-> left), getheight(y -> right))+ 1;

            return y;
        }

        Node* LeftRightRotation(Node* lr){
                     

        }


        Node* insert(Node* node , int key){
            if (node == nullptr){
                return new Node(key);

            }
            if(key< node->key){
                node->left= insert (node->left , key);
            }
            else if( key> node->key){
                node-> right = insert(node->right, key);
            }
            else{
                    return node;

            }

        }

};
int main()

{

    AVLTree tree;
    Node* root = nullptr;
    root = tree.insert(root, 10);
    root = tree.insert(root, 20);
    root = tree.insert(root, 30);
    root = tree.insert(root, 40);
    root = tree.insert(root, 50);
    root = tree.insert(root, 25);

    return 0;
}