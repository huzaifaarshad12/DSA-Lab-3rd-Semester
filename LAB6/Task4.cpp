#include <iostream>
#include <string>
using namespace std;

#define MAX 1000
//Reverse task 
int main() {
    string sentence = "I am from University of Engineering and Technology Lahore ";
    cout << "Original: " << sentence << endl;
    cout << "Reversed: ";
    reverseWords(sentence);
    return 0;
}
class Stack {
public:
    char arr[MAX];
    int top;

    Stack() { top = -1; }

    bool isFull() {
        return top == (MAX - 1);
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(char x) {
        if (isFull()) {
            cout << "Stack is full" << endl;
            return;
        }
        arr[++top] = x;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return '\0';
        }
        return arr[top--];
    }

    char Top() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return '\0';
        }
        return arr[top];
    }
};

void reverseWords(string sentence) {
    Stack charStack;
    Stack wordStack;
    string word;

    // Traverse the sentence character by character
    for (char ch : sentence) {
        if (ch != ' ') {
            charStack.push(ch); //push each character
        } else {
            while (!charStack.isEmpty()) {
                word += charStack.pop();
            }
            wordStack.push(' ');
            for (char wc : word) {
                wordStack.push(wc);
            }
            word = "";
        }
    }

    // Pop remaining characters in the charStack
    while (!charStack.isEmpty()) {
        word += charStack.pop();
    }
    for (char wc : word) {
        wordStack.push(wc);
    }

    // Pop words from wordStack to get the reversed sentence
    string reversedResult;
    while (!wordStack.isEmpty()) {
        reversedResult += wordStack.pop();
    }

    cout << reversedResult << endl;
}


