#pragma once


#include <stdexcept>
#include <iostream>
#include <string>
#include <iterator>
#include <stdio.h>
template <typename T>


class Node{
    public:
    T data;
    Node<T>* next;
    Node(T data) : data(data), next(nullptr) {}
};


template <typename T>
class stack{
    private:
        Node<T>* top;
    public:
        stack(): top(nullptr){}

    bool isEmpty()const {
        return top == nullptr;
    }

    void Push(T data){
        Node<T>* newNode = new Node<T>(data);
        newNode->next =top;
        top = newNode;
    }
    T Pop(){
        if(isEmpty()){
            throw std::runtime_error("Stack is empty");
        }
        T data = top->data;
        Node<T>* oldTop = top;
        top =top ->next;
        delete oldTop;
        return data;
    }
    T Peek()const{
        if(isEmpty()){
            throw std::runtime_error("Stack is empty");
        }
        return top->data;
    }

    //deconstructor 

    ~stack(){
        while(!isEmpty()){
            Pop();
        }
    }
//Iterator class for stack
class Iterator{
    private:
        Node<T>* current;

    public:
    Iterator(Node<T>* start): current(start){}

    T& operator*() const {
        return current -> data;
    }
    Iterator& operator++(){
        current = current -> next;
        return *this;
    }
    bool operator!=(const Iterator& other) const{
        return current != other.current;
    }

};

Iterator begin()const{
    return Iterator(top);
}
Iterator end() const {
    return Iterator(nullptr);
}

};