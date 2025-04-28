#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

using namespace std;

class Stack {
private:
    int top;
    int arr[1000];

public:
    Stack() { top = -1; }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 999;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack is full or overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty or underflow" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top];
    }

    void display() {
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    string toString() {
        string res = "";
        for (int i = 0; i <= top; i++) {
            res += to_string(arr[i]) + " ";
        }
        return res;
    }
};

void processInput(Stack &stack, const string &input) {
    stringstream ss(input);
    string token;
    while (ss >> token) 
    {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            stack.push(stoi(token));
        } else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%") {
            int b = stack.pop();
            int a = stack.pop();
            if (token == "+") stack.push(a + b);
            if (token == "-") stack.push(a - b);
            if (token == "*") stack.push(a * b);
            if (token == "/") stack.push(a / b);
            if (token == "%") stack.push(a % b);
        } else if (token == "?") {
            cout << stack.toString() << endl;
        } else if (token == "^") {
            cout << stack.pop() << endl;
        } else if (token == "!") {
            exit(0);
        } else {
            cout << "Invalid input" << endl;
        }
    }
}
int main() {
    Stack stack;
    string input;
    while (true) {
        cout << "Enter input: ";
        getline(cin, input);
        processInput(stack, input);
    }
    return 0;
}
