#include <iostream>
#define Max 1000 //maximum stack size
using namespace std;
// Implement stack using arrays

class Stack {
    int top;
public:
    int arr[Max];

    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x) 
{
    if (top >= (Max - 1)) 
    {
       cout << "Stack Overflow" << endl;
        return false;
    }
    else 
    {
        arr[++top] = x;
        cout << x << " pushed into stack" << endl;
        return true;
    }
}

int Stack::pop() 
{
    if (top < 0) 
    {
        cout << "Stack Underflow" << endl;
        return 0;
    } 
    else 
    {
        int x = arr[top--];
        return x;
    }
}

int Stack::peek() 
{
    if (top < 0) {
        cout << "Stack is Empty" << endl;
        return 0;
    } else 
    {
        int x = arr[top];
        return x;
    }
}

bool Stack::isEmpty() 
{
    return (top < 0);
}

int main() {
    Stack s;
    s.push(10); //if we push one elemnt then stack will become empty and top element will become 0
                //if we pop more than one element then like 10 and 20 then 20 will be popped and top element will become 10 
    //s.push(20);
   // s.push(30);
    //s.push(40);

    std::cout << s.pop() << " popped from stack" << std::endl;
    std::cout << "Top element is " << s.peek() << std::endl;
    std::cout << "Stack is empty: " << (s.isEmpty() ? "true" : "false") << std::endl; 
    return 0;
}

