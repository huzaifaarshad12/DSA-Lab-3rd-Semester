#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Deck.h"
#include "Card.h"
#include "TableauPile.h"
#include "FoundationPile.h"
#include "StockPile.h"

using namespace std;

class Game {
private:
    Deck deck;
    TableauPile* tableauPiles[7];
    FoundationPile* foundationPiles[4];
    StockPile* stockPile;

public://constructor
    Game() {
        for (int i = 0; i < 7; i++) {
            tableauPiles[i] = new TableauPile(deck, i + 1);
        }
        
        for (int i = 0; i < 4; i++) {
            foundationPiles[i] = new FoundationPile();
        }
        
        stockPile = new StockPile(deck);
    }

    void displayTableauPiles() const {
        for (int i = 0; i < 7; i++) {
            cout << "Tableau Pile " << (i + 1) << ": " << endl;
            tableauPiles[i]->display();
        }
    }

    void displayFoundationPiles() const {
        for (int i = 0; i < 4; i++) {
            cout << "Foundation Pile " << (i + 1) << ": " << endl;
            foundationPiles[i]->display();
        }
    }

    void displayStockPile() const {
        stockPile->display(); 
    }

    // Move card from tableau pile to tableau pile
    void moveTableauToTableau(int sourcePile, int destinationPile) {
        if (sourcePile < 0 || sourcePile >= 7 || destinationPile < 0 || destinationPile >= 7) {
            cout << "Invalid pile numbers." << endl;
            return;
        }

        Card sourceCard = tableauPiles[sourcePile]->getTopCard();
        Card destCard = tableauPiles[destinationPile]->getTopCard();

        if (isMoveAllowed(sourceCard, destCard)) {
            tableauPiles[destinationPile]->addCard(tableauPiles[sourcePile]->removeCard());
        } else {
            cout << "Move not allowed." << endl;
        }
    }


    

    // Move card from tableau pile to foundation pile
    void moveTableauToFoundation(int sourcePile, int foundationPile) {
        if (sourcePile < 0 || sourcePile >= 7 || foundationPile < 0 || foundationPile >= 4) {
            cout << "Invalid pile numbers." << endl;
            return;
        }

        Card sourceCard = tableauPiles[sourcePile]->getTopCard();
        if (foundationPiles[foundationPile]->canAddCard(sourceCard)) {
            foundationPiles[foundationPile]->addCard(tableauPiles[sourcePile]->removeCard());
        } else {
            cout << "Move not allowed." << endl;
        }
    }

    // Move card from stock pile to tableau pile
    void moveStockToTableau(int stockIndex, int tableauPileIndex) {
        if (tableauPileIndex < 0 || tableauPileIndex >= 7) {
            cout << "Invalid tableau pile number." << endl;
            return;
        }

        Card stockCard = stockPile->removeCardAt(stockIndex);
        tableauPiles[tableauPileIndex]->addCard(stockCard);
    }

    // Move card from stock pile to foundation pile
    void moveStockToFoundation(int stockIndex, int foundationPileIndex) {
        if (foundationPileIndex < 0 || foundationPileIndex >= 4) {
            cout << "Invalid foundation pile number." << endl;
            return;
        }

        Card stockCard = stockPile->removeCardAt(stockIndex);
        if (foundationPiles[foundationPileIndex]->canAddCard(stockCard)) {
            foundationPiles[foundationPileIndex]->addCard(stockCard);
        } else {
            cout << "Move not allowed." << endl;
        }
    }
        bool isWinner() const {
        for (int i = 0; i < 4; i++) {
            if (foundationPiles[i]->getTopCard().rank != "K") {
                return false;
            }
        }
        return true;}

private:
    // Check if the move is allowed between two cards
    bool isMoveAllowed(Card sourceCard, Card destCard) const {
        return (rankinInt(sourceCard.rank) == rankinInt(destCard.rank) - 1) &&
               !isSameColor(sourceCard.suit, destCard.suit);
    }

    // Check if two suits are of the same color
    bool isSameColor(string suit1, string suit2) const {
        return (suit1 == "Hearts" || suit1 == "Diamonds") && (suit2 == "Hearts" || suit2 == "Diamonds") ||
               (suit1 == "Clubs" || suit1 == "Spades") && (suit2 == "Clubs" || suit2 == "Spades");
    }

    int rankinInt(string rank) const {
        if (rank == "J") return 11;
        if (rank == "Q") return 12;
        if (rank == "K") return 13;
        if (rank == "A") return 1;
        return stoi(rank); // For numbers 2-10
    }
};
