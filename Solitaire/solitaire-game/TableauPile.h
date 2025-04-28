#pragma once


#include <iostream>
#include "Stack.h"
#include <vector>
#include <algorithm>
#include "Card.h"  
#include "Deck.h"  
#include <string>

using namespace std;

class TableauPile {
private:
    stack<Card> pile;

public:
    //concstuctor
    TableauPile(Deck& deck, int numCards) {
    for (int i = 0; i < numCards; ++i) {
        Card* cardPtr = deck.dealCard();  
        Card card = *cardPtr; 
        card.isFaceup = (i == numCards - 1);  
        pile.Push(card);
    }
    }
    void addCard(const Card& card) {
        pile.Push(card);
    }

Card removeCard(){
    if (pile.isEmpty()) {
        throw std::out_of_range("No cards left to remove.");
    }

    Card removedCard = pile.Peek();  
    pile.Pop();  


    if (!pile.isEmpty()) {
        
        Card topCard = pile.Peek();  
        topCard.isFaceup = true;    
    }
    return removedCard;  
}


    Card getTopCard() const {
        if (pile.isEmpty()) {
            throw out_of_range("Pile is empty.");
        }
        return pile.Peek();
    }

    // Displays all the cards in the tableau pile from bottom to top
    void display() const {
        vector<Card> cardsList;
        stack<Card> tempPile = pile;

        while (!tempPile.isEmpty()) {
            cardsList.push_back(tempPile.Peek());
            tempPile.Pop();
        }

        reverse(cardsList.begin(), cardsList.end());

        for (const auto& card : cardsList) {
            cout << card.ToString() << "\t"; 
            
        }

        cout << endl;
        cout<<"---------------------------------"<<endl;
    }

};