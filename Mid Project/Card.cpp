//phase 1 card class




#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

class Card {
public:
    std::string suit;
    int rank;
    bool faceUp;

    // Constructor for the Card class
    Card(std::string s, int r, bool face) : suit(s), rank(r), faceUp(face) {}

    // Method to display the card
    void display() const {
        if (faceUp) {
            std::string rankString;
            switch (rank) {
                case 1: rankString = "Ace"; break;
                case 11: rankString = "Jack"; break;
                case 12: rankString = "Queen"; break;
                case 13: rankString = "King"; break;
                default: rankString = std::to_string(rank); break;
            }
            std::cout << rankString << " of " << suit;
        } else {
            std::cout << "Face Down";
        }
    }

    // Method to flip the card (face-up or face-down)
    void flip() {
        faceUp = !faceUp;
    }
};
