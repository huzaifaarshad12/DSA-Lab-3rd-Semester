//Phase 3: Game Logic Implement move validation, stockpile drawing, card flipping, and undo functionality. 






#include <iostream>
#include <stack>
#include <vector>
#include <stdexcept>
#include <deque>

// Forward declaration of classes
class Card;
class TableauPile;
class FoundationPile;
class Stockpile;

// A structure to hold move history for undo functionality
struct Move {
    bool isTableauMove;   // True if the move was between tableau piles
    int sourcePileIndex;
    int destPileIndex;
    Card movedCard;
};

// Game class to manage the logic
class Game {
private:
    std::vector<TableauPile> tableau;       // 7 tableau piles
    std::vector<FoundationPile> foundation; // 4 foundation piles
    Stockpile stockpile;                    // Stockpile (draw pile)
    std::deque<Move> moveHistory;           // History for undo functionality

public:
    Game();

    // Draw a card from the stockpile
    void drawCard();

    // Move a card from one tableau pile to another
    void moveCardBetweenTableau(int source, int dest);

    // Move a card from tableau to foundation
    void moveToFoundation(int tableauIndex, int foundationIndex);

    // Undo the last move
    void undoMove();

    // Check if the move is valid between tableau piles
    bool validateMoveTableau(int source, int dest) const;

    // Display the game state
    void displayState() const;
};

// Stockpile class
class Stockpile {
public:
    std::stack<Card> pile;

    // Method to draw a card from the stockpile
    Card drawCard() {
        if (pile.empty()) {
            throw std::out_of_range("Stockpile is empty.");
        }
        Card topCard = pile.top();
        pile.pop();
        return topCard;
    }

    // Add cards to the stockpile
    void addCard(Card card) {
        pile.push(card);
    }
};

// Card class
class Card {
public:
    std::string suit;
    int rank;
    bool faceUp;

    Card(std::string s, int r, bool face) : suit(s), rank(r), faceUp(face) {}

    void flip() {
        faceUp = !faceUp;
    }

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
};

// TableauPile class
class TableauPile {
public:
    std::stack<Card> pile;

    void addCard(Card card) {
        pile.push(card);
    }

    Card removeCard() {
        if (pile.empty()) {
            throw std::out_of_range("No card to remove from tableau pile.");
        }
        Card topCard = pile.top();
        pile.pop();
        return topCard;
    }

    void displayPile() const {
        std::stack<Card> temp = pile;
        while (!temp.empty()) {
            temp.top().display();
            std::cout << std::endl;
            temp.pop();
        }
    }
};

// FoundationPile class
class FoundationPile {
public:
    std::stack<Card> pile;

    bool canPlaceCard(Card card) const {
        if (pile.empty()) {
            return card.rank == 1; // Ace starts the foundation
        }
        Card topCard = pile.top();
        return (topCard.suit == card.suit && topCard.rank == card.rank - 1);
    }

    void placeCard(Card card) {
        if (canPlaceCard(card)) {
            pile.push(card);
        } else {
            throw std::invalid_argument("Cannot place this card on the foundation pile.");
        }
    }

    void displayPile() const {
        if (!pile.empty()) {
            pile.top().display();
        } else {
            std::cout << "Empty";
        }
    }
};

// Game constructor
Game::Game() {
    tableau.resize(7);
    foundation.resize(4);
    // Initialize stockpile (for simplicity, not fully implemented)
}

// Draw a card from the stockpile
void Game::drawCard() {
    try {
        Card drawnCard = stockpile.drawCard();
        tableau[0].addCard(drawnCard);  // Add drawn card to tableau (for now)
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

// Move a card between tableau piles
void Game::moveCardBetweenTableau(int source, int dest) {
    if (!validateMoveTableau(source, dest)) {
        std::cerr << "Invalid move between tableau piles." << std::endl;
        return;
    }

    Card movedCard = tableau[source].removeCard();
    tableau[dest].addCard(movedCard);

    // Record the move for undo functionality
    moveHistory.push_back({true, source, dest, movedCard});
}

// Validate move between tableau piles
bool Game::validateMoveTableau(int source, int dest) const {
    // Add rules for alternating colors and sequential ranks
    if (tableau[source].pile.empty()) return false;

    Card sourceCard = tableau[source].pile.top();
    if (tableau[dest].pile.empty()) return true;

    Card destCard = tableau[dest].pile.top();
    // Cards must be alternating colors and in sequential order
    return (sourceCard.rank == destCard.rank - 1);  // Add alternating color logic
}

// Move a card from tableau to foundation
void Game::moveToFoundation(int tableauIndex, int foundationIndex) {
    if (tableau[tableauIndex].pile.empty()) {
        std::cerr << "Tableau pile is empty." << std::endl;
        return;
    }

    Card cardToMove = tableau[tableauIndex].removeCard();
    foundation[foundationIndex].placeCard(cardToMove);

    // Record the move for undo functionality
    moveHistory.push_back({true, tableauIndex, foundationIndex, cardToMove});
}

// Undo the last move
void Game::undoMove() {
    if (moveHistory.empty()) {
        std::cerr << "No moves to undo." << std::endl;
        return;
    }

    Move lastMove = moveHistory.back();
    moveHistory.pop_back();

    // Undo logic for tableau-to-tableau or tableau-to-foundation
    if (lastMove.isTableauMove) {
        tableau[lastMove.sourcePileIndex].addCard(lastMove.movedCard);
        tableau[lastMove.destPileIndex].removeCard();  // Reverse the move
    }
}

// Display the current state of the game
void Game::displayState() const {
    std::cout << "Tableau Piles: " << std::endl;
    for (int i = 0; i < tableau.size(); ++i) {
        std::cout << "Pile " << i + 1 << ": ";
        tableau[i].displayPile();
        std::cout << std::endl;
    }

    std::cout << "Foundation Piles: " << std::endl;
    for (int i = 0; i < foundation.size(); ++i) {
        std::cout << "Foundation " << i + 1 << ": ";
        foundation[i].displayPile();
        std::cout << std::endl;
    }
}

// Main function to test the game logic
int main() {
    Game game;

    // Example moves for testing
    game.displayState();
    game.drawCard();  // Draw a card
    game.moveCardBetweenTableau(0, 1);  // Move card from tableau[0] to tableau[1]
    game.moveToFoundation(0, 0);       // Move card from tableau[0] to foundation[0]
