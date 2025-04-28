#include <iostream>
using namespace std;
//implement queue using linked lists


class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << x << " enqueued to queue" << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        } else {
            Node* temp = front;
            front = front->next;
            if (front == nullptr) {
                rear = nullptr;
            }
            int dequeued = temp->data;
            delete temp;
            return dequeued;
        }
    }

    int frontItem() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    int rearItem() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return rear->data;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};
int main() {
    Queue q;

    q.enqueue(10);//insert into queue
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << q.dequeue() << " dequeued from queue" << endl; //delete from queue// 10 is deleted
    cout << q.dequeue() << " dequeued from queue" << endl; // 20 is deleted
    cout << q.dequeue() << " dequeued from queue" << endl;//30 is deleted
    
    cout << "Front item is " << q.frontItem() << endl;//front is 40
    cout << "Rear item is " << q.rearItem() << endl;//rear is 40

    return 0;
}

