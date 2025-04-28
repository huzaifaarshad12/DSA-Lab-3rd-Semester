//Phase 4: User 
//Interface (Optional) 
//Create a text-based or graphical interface to interact with the game. Display the tableau, 
//stockpile,  
//and foundation





#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <stdexcept>

using namespace std;

// Forward declaration of classes
class Card;
class TableauPile;
class FoundationPile;
class Stockpile;

// Game class to manage the game logic and UI
class Game {
private:
    vector<TableauPile> tableau;       // 7 tableau piles
    vector<FoundationPile> foundation; // 4 foundation piles
    Stockpile stockpile;               // Stockpile (draw pile)
    deque<Move> moveHistory;           // History for undo functionality

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

    // Start game loop
    void startGame();
};

// Stockpile class
class Stockpile {
public:
    stack<Card> pile;

    Card drawCard() {
        if (pile.empty()) {
            throw out_of_range("Stockpile is empty.");
        }
        Card topCard = pile.top();
        pile.pop();
        return topCard;
    }

    void addCard(Card card) {
        pile.push(card);
    }
};

// Card class
class Card {
public:
    string suit;
    int rank;
    bool faceUp;

    Card(string s, int r, bool face) : suit(s), rank(r), faceUp(face) {}

    void flip() {
        faceUp = !faceUp;
    }

    void display() const {
        if (faceUp) {
            string rankString;
            switch (rank) {
                case 1: rankString = "Ace"; break;
                case 11: rankString = "Jack"; break;
                case 12: rankString = "Queen"; break;
                case 13: rankString = "King"; break;
                default: rankString = to_string(rank); break;
            }
            cout << rankString << " of " << suit;
        } else {
            cout << "Face Down";
        }
    }
};

// TableauPile class
class TableauPile {
public:
    stack<Card> pile;

    void addCard(Card card) {
        pile.push(card);
    }

    Card removeCard() {
        if (pile.empty()) {
            throw out_of_range("No card to remove from tableau pile.");
        }
        Card topCard = pile.top();
        pile.pop();
        return topCard;
    }

    void displayPile() const {
        stack<Card> temp = pile;
        while (!temp.empty()) {
            temp.top().display();
            cout << endl;
            temp.pop();
        }
    }
};

// FoundationPile class
class FoundationPile {
public:
    stack<Card> pile;

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
            throw invalid_argument("Cannot place this card on the foundation pile.");
        }
    }

    void displayPile() const {
        if (!pile.empty()) {
            pile.top().display();
        } else {
            cout << "Empty";
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
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
}

// Move a card between tableau piles
void Game::moveCardBetweenTableau(int source, int dest) {
    if (!validateMoveTableau(source, dest)) {
        cerr << "Invalid move between tableau piles." << endl;
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
        cerr << "Tableau pile is empty." << endl;
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
        cerr << "No moves to undo." << endl;
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
    cout << "\n--- Current Game State ---\n";

    // Display tableau piles
    cout << "\nTableau Piles:\n";
    for (int i = 0; i < tableau.size(); ++i) {
        cout << "Pile " << i + 1 << ": ";
        tableau[i].displayPile();
        cout << endl;
    }

    // Display foundation piles
    cout << "\nFoundation Piles:\n";
    for (int i = 0; i < foundation.size(); ++i) {
        cout << "Foundation " << i + 1 << ": ";
        foundation[i].displayPile();
        cout << endl;
    }

    // Display stockpile
    cout << "\nStockpile (Top Card): ";
    if (!stockpile.pile.empty()) {
        stockpile.pile.top().display();
    } else {
        cout << "Empty";
    }
    cout << endl;
}

// Game loop to handle user interaction
void Game::startGame() {
    string command;
    while (true) {
        displayState();
        cout << "\nEnter a command (draw, move, undo, quit): ";
        cin >> command;

        if (command == "draw") {
            drawCard();
        } else if (command == "move") {
            int source, dest;
            cout << "Enter source pile index (1-7): ";
            cin >> source;
            cout << "Enter destination pile index (1-7): ";
            cin >> dest;
            moveCardBetweenTableau(source - 1, dest - 1);  // 0-based indexing
        } else if (command == "undo") {
            undoMove();
        } else if (command == "quit") {
            break;
        } else {
            cout << "Invalid command. Try again.\n";
        }
    }
}

int main() {
    Game game;
    game.startGame();  // Start the game
    return 0;
}
