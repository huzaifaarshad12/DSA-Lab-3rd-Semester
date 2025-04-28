#include <iostream>
using namespace std;

#define Max 1000 // max queue size
//implement queue using arrays
class Queue {
    int front, rear, size;
    int arr[Max];

public:
    Queue() {
        front = size = 0;
        rear = Max - 1;
    }

    bool isFull() {
        return size == Max;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int item) 
    {
        if (isFull()) {
            cout << "Queue is full"<<endl;
            return;
        }
        rear = (rear + 1) % Max;
        arr[rear] = item;
        size++;
        cout <<item<< "enqueued to queue"<< endl;
    }


    int dequeue() 
    {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int item = arr[front];
        front = (front + 1) % Max;
        size--;
        return item;
    }

    int frontItem() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    int rearItem() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[rear];
    }
};

int main() {
    Queue q;

    q.enqueue(10);//insert into queue
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << q.dequeue() << " dequeued from queue" << endl; //delete from queue// 10 is deleted
    cout << q.dequeue() << " dequeued from queue" << endl;// 20 is deleted
    cout << q.dequeue() << " dequeued from queue" << endl;//30 is deleted

    cout << "Front item is " << q.frontItem() << endl;// front is 40
    cout << "Rear item is " << q.rearItem() << endl; //end is 40

    return 0;
}
