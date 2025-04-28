#include <iostream>
#include <stack>
using namespace std;
//Implement steue by using two stacks.
//We will use two stacks in this scenario.
class Steue {
private:
    stack<int> s1, s2;

public:
    // insert to end of the Steue
    void enqueue(int x) {
        s1.push(x);
    }

    // Remove or delete from the front of the Steue
    int dequeue() {
        if (s2.empty()) {
            if (s1.empty()) {
                cout << "Steue is empty" << endl;
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

    // Get the front element
    int front() {
        if (s2.empty()) {
            if (s1.empty()) {
                cout << "Steue is empty" << endl;
                return -1;
            }
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    // Get the rear element
    int rear() {
        if (s1.empty()) {
            if (s2.empty()) {
                cout << "Steue is empty" << endl;
                return -1;
            }
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
        return s1.top();
    }

    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    Steue steue;

    steue.enqueue(15);
    steue.enqueue(30);
    steue.enqueue(45);

    cout << steue.dequeue() << " dequeued from Steue" << endl;

    cout << "Front item is " << steue.front() << endl;
    cout << "Rear item is " << steue.rear() << endl;

    steue.dequeue();
    steue.dequeue();

    cout << "Steue is empty: " << (steue.isEmpty() ? "true" : "false") << endl;

    return 0;
}
