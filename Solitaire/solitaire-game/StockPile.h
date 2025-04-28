
#include <iostream>
#include <stdexcept>
#include "Card.h"
#include "Deck.h"
#include "Stack.h"

using namespace std;

class StockPile {
private:
    struct Node {
        Card card;
        Node* next;

        Node(const Card& card) : card(card), next(nullptr) {}
    };

    Node* head;  
    int size;   

public:

    StockPile(Deck& deck) : head(nullptr), size(0) {
        for (int i = 0; i < 24; i++) {
            Card* card = deck.dealCard();
            card->isFaceup = true;   
            addLast(*card);        
        }
    }

    ~StockPile() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // this is the function to add a card to the end of the linked list
    void addLast(const Card& card) {
        Node* newNode = new Node(card);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }
        //this is function to get card at specific index
    Card getCardAt(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Invalid card index.");
        }

        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->card;
    }

    Card removeCardAt(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Invalid card index.");
        }

        Node* temp = head;
        Node* prev = nullptr;

        for (int i = 0; i < index; i++) {
            prev = temp;
            temp = temp->next;
        }

        Card card = temp->card;
        
        if (prev == nullptr) {  
            head = head->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        size--;

        return card;
    }

    void display() const {
        cout << "Stock Pile (24 Cards): " << endl;
        Node* temp = head;
        int index = 0;

        while (temp != nullptr) {
            cout << "[" << index << "] " << temp->card.ToString() << "\t"; 
            temp = temp->next;
            index++;
        }
        cout << endl;
    }
};
