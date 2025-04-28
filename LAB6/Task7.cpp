#include <iostream>
#include <stack>
using namespace std;
//implement queue by using stack.
//We will use two stacks in this scenario.

class Queue {
private:
    stack<int> s1, s2;

public:
//insert function
    void enqueue(int x) {
        s1.push(x);
    }
//delete function
    int dequeue() {
        if (s2.empty()) {
            if (s1.empty()) {
                cout << "Queue is empty" << endl;
                return -1;
            }
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }
//top function
    int top() {
        if (s2.empty()) {
            if (s1.empty()) {
                cout << "Queue is empty" << endl;
                return -1;
            }
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool isEmpty() {
        return s1.empty() && s2.empty();
    }

    void push(int x) {
        enqueue(x);
    }

    void pop() {
        dequeue();
    }
};
int main() {
    Queue q;
    q.push(15);
    q.push(30);
    q.push(45);

    cout << q.top() << " is on top of the queue" << endl;

    q.pop();
    cout << q.top() << " is on top of the queue" << endl;

    q.pop();
    //q.pop();

    cout << q.top() << " is on top of the queue" << endl;

    q.pop();
    cout << "Queue is empty: " << (q.isEmpty() ? "true" : "false") << endl;

    return 0;
}