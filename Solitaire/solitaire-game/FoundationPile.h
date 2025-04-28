#include <vector>
#include <string>
#include "Card.h"
#include "Stack.h"
using namespace std;

class FoundationPile {
private:
    stack<Card> pile;

    // Helper function to convert rank to an integer for comparison
    int rankInInt(const string& rank) const {
        if (rank == "J") return 11;
        if (rank == "Q") return 12;
        if (rank == "K") return 13;
        if (rank == "A") return 1;
        return stoi(rank);  // Convert rank (2-10) directly to int
    }

public:
    FoundationPile() {}

    void addCard(const Card& card) {
        if (pile.isEmpty()) {
            if (card.rank == "A") {
                pile.Push(card);
            }
        } else {
            Card topCard = pile.Peek();
            if (card.suit == topCard.suit && rankInInt(card.rank) == rankInInt(topCard.rank) + 1) {
                pile.Push(card);
            }
        }
    }

    Card removeCard() {
        return pile.Pop();
    }

    Card getTopCard() const {
        return pile.Peek();
    }

    void display() const {
        if (pile.isEmpty()) {
            cout << "XXX" << endl;
        } else {
            cout << pile.Peek().ToString() << endl;
        }
        cout<<"---------------------------------"<<endl;
    }

    bool canAddCard(const Card& card) const {
        if (pile.isEmpty()) {
            return card.rank == "A";  // Only an Ace can start the pile
        }

        Card topCard = pile.Peek();
        return card.suit == topCard.suit && rankInInt(card.rank) == rankInInt(topCard.rank) + 1;
    }
};