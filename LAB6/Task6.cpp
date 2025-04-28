#include <iostream>
#include <queue>
using namespace std;
//implement stack by using queue
//for stack implementation we will use two queues

class Stack {
private:
    queue<int> q1, q2;

public:
//enqueue or insert function
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
//dequeue or delete function
    void pop() {
        if (q1.empty()) {
            cout << "Stack Underflow" << endl;
            return;
        }
        q1.pop();
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};
int main() {
    Stack s;
    s.push(15);
    s.push(30);
    s.push(45);

    //s.push(30);// first if two elements 10 and 20 are pushed, first it will show 20 will be popped and then it will show 10 will be popped.
                    //then it will show stack underflow and stack is empty because stack becomes empty 
    //s.push(40);


    cout << s.top() << " is on top of the stack" << endl;

    s.pop();
    cout << s.top() << " is on top of the stack" << endl;

    s.pop();
    s.pop();

    cout << s.top() << " is on top of the stack" << endl;

    s.pop();
    cout << "Stack is empty: " << (s.empty() ? "true" : "false") << endl;

    return 0;
}