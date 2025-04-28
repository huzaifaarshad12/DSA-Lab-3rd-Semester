#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Card.h"

class Deck {
public:
    std::vector<Card> cards;

    // Constructor to initialize the deck
    Deck() {
        std::vector<std::string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
        
        // Create the deck with all 52 cards
        for (const auto& suit : suits) {
            for (int rank = 1; rank <= 13; ++rank) {
                cards.push_back(Card(suit, rank, false)); // All cards are initially face-down
            }
        }
    }

    // Method to shuffle the deck
    void shuffleDeck() {
        srand(static_cast<unsigned>(time(0)));  // Seed for randomness
        for (int i = 0; i < cards.size(); ++i) {
            // Swap the current card with a random card
            int randIndex = rand() % cards.size();
            std::swap(cards[i], cards[randIndex]);
        }
    }

    // Method to deal a card (return the top card and remove it from the deck)
    Card dealCard() {
        if (cards.empty()) {
            throw std::out_of_range("No cards left to deal.");
        }
        Card topCard = cards.back();
        cards.pop_back();  // Remove the card from the deck
        return topCard;
    }

    // Method to display the deck
    void displayDeck() const {
        for (const auto& card : cards) {
            card.display();
            std::cout << std::endl;
        }
    }
};
