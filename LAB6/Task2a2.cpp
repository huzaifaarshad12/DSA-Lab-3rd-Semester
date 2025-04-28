#include <iostream>
using namespace std;
// implement stack by using linked lists.

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Stack 
{
private:
    Node* top;

public:
    Stack() : top(nullptr) {}
    bool isEmpty() {
        return top == nullptr;
    }
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        cout << x << " pushed into stack" << endl;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        } else {
            Node* temp = top;
            top = top->next;
            int popped = temp->data;
            delete temp;
            return popped;
        }
    }
    int Top() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        } else {
            return top->data;
        }
    }
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack s;
    s.push(10); //if we push one elemnt then stack will become empty and top element will become -1
                //if we pop more than one element then like 10 and 20 then 20 will be popped and top element will become 10 
    s.push(20);
   // s.push(30);
    //s.push(40);

    cout << s.pop() << " popped from stack" << endl;
    cout << "Top element is " << s.Top() << endl;
    cout << "Stack is empty: " << (s.isEmpty() ? "true" : "false") << endl;

    return 0;
}