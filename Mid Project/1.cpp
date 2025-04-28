#include <iostream>
#include <stack>
#include <string>





//Stack (FIFO)





// Define the Card class for representing each card
class Card {
public:
    std::string suit;
    int rank;
    bool faceUp;

    Card(std::string s, int r, bool face) : suit(s), rank(r), faceUp(face) {}

    void display() const {
        if (faceUp)
            std::cout << rank << " of " << suit;
        else
            std::cout << "Face Down";
    }
};

// Define the Stack class to manage piles of cards
class CardStack {
private:
    std::stack<Card> pile;

public:
    // Push a card onto the stack
    void push(const Card& card) {
        pile.push(card);
    }

    // Pop a card from the stack if not empty
    Card pop() {
        if (!pile.empty()) {
            Card topCard = pile.top();
            pile.pop();
            return topCard;
        } else {
            throw std::out_of_range("Stack is empty");
        }
    }

    // Peek at the top card (view without removing)
    Card& top() {
        if (!pile.empty()) {
            return pile.top();
        } else {
            throw std::out_of_range("Stack is empty");
        }
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return pile.empty();
    }

    // Display the top card
    void displayTopCard() const {
        if (!pile.empty()) {
            pile.top().display();
            std::cout << std::endl;
        } else {
            std::cout << "Empty pile" << std::endl;
        }
    }
};

// int main() {
//     // Create a sample stack and add cards to it
//     CardStack tableauColumn;

//     // Add cards (example with arbitrary face-up status)
//     tableauColumn.push(Card("Hearts", 7, true));
//     tableauColumn.push(Card("Spades", 5, false));
//     tableauColumn.push(Card("Diamonds", 3, true));

//     // Display the top card
//     std::cout << "Top card in tableau column: ";
//     tableauColumn.displayTopCard();

//     // Example of popping the top card
//     tableauColumn.pop();

//     // Display the new top card
//     std::cout << "New top card after pop: ";
//     tableauColumn.displayTopCard();

//     return 0;
// }
#include <iostream>
#include <queue>
#include <vector>
#include <string>

// Define the Card class for representing each card (same as previous)
class Card {
public:
    std::string suit;
    int rank;
    bool faceUp;

    Card(std::string s, int r, bool face) : suit(s), rank(r), faceUp(face) {}

    void display() const {
        if (faceUp)
            std::cout << rank << " of " << suit;
        else
            std::cout << "Face Down";
    }
};




//Queue(LIFO)





// Define the CardQueue class to manage the stockpile (FIFO)
class CardQueue {
private:
    std::queue<Card> stockpile;

public:
    // Enqueue a card to the back of the queue
    void enqueue(const Card& card) {
        stockpile.push(card);
    }

    // Draw one card from the front of the queue (if not empty)
    Card drawOne() {
        if (!stockpile.empty()) {
            Card drawnCard = stockpile.front();
            stockpile.pop();
            return drawnCard;
        } else {
            throw std::out_of_range("Stockpile is empty");
        }
    }

    // Draw three cards from the front of the queue, if possible
    std::vector<Card> drawThree() {
        std::vector<Card> drawnCards;
        int count = 0;

        // Draw up to three cards if available
        while (!stockpile.empty() && count < 3) {
            drawnCards.push_back(stockpile.front());
            stockpile.pop();
            count++;
        }
        return drawnCards;
    }

    // Check if the stockpile is empty
    bool isEmpty() const {
        return stockpile.empty();
    }

    // Display the next card to be drawn without removing it
    void displayNextCard() const {
        if (!stockpile.empty()) {
            stockpile.front().display();
            std::cout << std::endl;
        } else {
            std::cout << "Stockpile is empty" << std::endl;
        }
    }
};

// int main() {
//     // Create a sample stockpile and add cards to it
//     CardQueue stockpile;

//     // Enqueue cards (example with arbitrary face-up status)
//     stockpile.enqueue(Card("Hearts", 10, false));
//     stockpile.enqueue(Card("Clubs", 2, false));
//     stockpile.enqueue(Card("Spades", 5, false));
//     stockpile.enqueue(Card("Diamonds", 7, false));

//     // Display the next card to be drawn
//     std::cout << "Next card in stockpile: ";
//     stockpile.displayNextCard();

//     // Draw one card
//     Card drawnCard = stockpile.drawOne();
//     std::cout << "Card drawn: ";
//     drawnCard.display();
//     std::cout << std::endl;

//     // Draw three cards
//     std::vector<Card> threeCards = stockpile.drawThree();
//     std::cout << "Three cards drawn: ";
//     for (const auto& card : threeCards) {
//         card.display();
//         std::cout << "  ";
//     }
//     std::cout << std::endl;

//     // Check if the stockpile is empty
//     std::cout << "Is stockpile empty? " << (stockpile.isEmpty() ? "Yes" : "No") << std::endl;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>

// Define the Card class for representing each card (same as before)
class Card {
public:
    std::string suit;
    int rank;
    bool faceUp;

    Card(std::string s, int r, bool face) : suit(s), rank(r), faceUp(face) {}

    void display() const {
        if (faceUp)
            std::cout << rank << " of " << suit;
        else
            std::cout << "Face Down";
    }
};





//Arrays/List





// Define the Deck class to manage the 52 cards
class Deck {
private:
    std::vector<Card> cards;

public:
    // Constructor to initialize and create a standard 52-card deck
    Deck() {
        std::string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
        
        // Populate the deck with cards for each suit and rank
        for (const auto& suit : suits) {
            for (int rank = 1; rank <= 13; ++rank) {  // Rank 1 to 13 (Ace to King)
                cards.push_back(Card(suit, rank, false));  // Cards start face-down
            }
        }
    }

    // Shuffle the deck
    void shuffleDeck() {
        // Seed with current time to get different results each run
        std::srand(static_cast<unsigned>(std::time(0)));
        std::random_shuffle(cards.begin(), cards.end());
    }

    // Deal a card from the deck
    Card dealCard() {
        if (!cards.empty()) {
            Card dealtCard = cards.back();
            cards.pop_back();
            return dealtCard;
        } else {
            throw std::out_of_range("No cards left to deal");
        }
    }

    // Display all cards in the deck (for debugging or testing)
    void displayDeck() const {
        for (const auto& card : cards) {
            card.display();
            std::cout << ", ";
        }
        std::cout << std::endl;
    }

    // Check if the deck is empty
    bool isEmpty() const {
        return cards.empty();
    }
};

// int main() {
//     // Create a deck of 52 cards
//     Deck deck;

//     // Shuffle the deck
//     deck.shuffleDeck();

//     // Display the shuffled deck
//     std::cout << "Shuffled deck:" << std::endl;
//     deck.displayDeck();

//     // Deal a few cards
//     std::cout << "Dealing some cards:" << std::endl;
//     for (int i = 0; i < 5; ++i) {
//         Card dealtCard = deck.dealCard();
//         dealtCard.display();
//         std::cout << std::endl;
//     }

//     // Check if deck is empty after dealing
//     std::cout << "Is the deck empty? " << (deck.isEmpty() ? "Yes" : "No") << std::endl;

//     return 0;
// }




//LinkedList implementation 





#include <iostream>
#include <string>

// Define the Card class for representing each card (same as before)
class Card {
public:
    std::string suit;
    int rank;
    bool faceUp;

    Card(std::string s, int r, bool face) : suit(s), rank(r), faceUp(face) {}

    void display() const {
        if (faceUp)
            std::cout << rank << " of " << suit;
        else
            std::cout << "Face Down";
    }
};

// Define the Node structure to represent each card in the linked list
struct Node {
    Card card;
    Node* next;

    Node(Card c) : card(c), next(nullptr) {}
};

// Define the LinkedList class to represent a tableau pile
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Add a card to the top of the pile (push front)
    void addCard(const Card& card) {
        Node* newNode = new Node(card);
        newNode->next = head;
        head = newNode;
    }

    // Remove a card from the top of the pile (pop front)
    Card removeCard() {
        if (head == nullptr) {
            throw std::out_of_range("No cards to remove in the tableau pile");
        }

        Node* temp = head;
        Card removedCard = head->card;
        head = head->next;
        delete temp;
        return removedCard;
    }

    // Flip the top card in the pile to face up
    void flipTopCard() {
        if (head != nullptr && !head->card.faceUp) {
            head->card.faceUp = true;
        }
    }

    // Display all cards in the pile (top to bottom)
    void displayPile() const {
        Node* current = head;
        while (current != nullptr) {
            current->card.display();
            std::cout << " -> ";
            current = current->next;
        }
        std::cout << "NULL" << std::endl;
    }

    // Check if the pile is empty
    bool isEmpty() const {
        return head == nullptr;
    }

    // Destructor to clean up linked list nodes
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// int main() {
//     // Create a tableau pile as a linked list
//     LinkedList tableauPile;

//     // Add cards to the tableau pile (example with arbitrary face-up status)
//     tableauPile.addCard(Card("Hearts", 7, false));
//     tableauPile.addCard(Card("Spades", 5, true));
//     tableauPile.addCard(Card("Diamonds", 3, false));

//     // Display the tableau pile
//     std::cout << "Tableau pile: ";
//     tableauPile.displayPile();

//     // Flip the top card if it's face down
//     tableauPile.flipTopCard();

//     // Display the tableau pile after flipping the top card
//     std::cout << "Tableau pile after flipping the top card: ";
//     tableauPile.displayPile();

//     // Remove a card from the top
//     Card removedCard = tableauPile.removeCard();
//     std::cout << "Removed card: ";
//     removedCard.display();
//     std::cout << std::endl;

//     // Display the tableau pile after removal
//     std::cout << "Tableau pile after removing the top card: ";
//     tableauPile.displayPile();

//     return 0;
// }





//HashMap implementation




#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

// Define the Card class (same as before)
class Card {
public:
    std::string suit;
    int rank;
    bool faceUp;

    Card(std::string s, int r, bool face) : suit(s), rank(r), faceUp(face) {}

    void display() const {
        if (faceUp)
            std::cout << rank << " of " << suit;
        else
            std::cout << "Face Down";
    }
};

// Define the GameMap class to track card positions, states, and pile locations
class GameMap {
private:
    // Map each pile identifier (e.g., "Tableau1", "FoundationA") to a vector of cards
    std::unordered_map<std::string, std::vector<Card>> piles;

public:
    // Add a card to a specific pile
    void addCardToPile(const std::string& pileName, const Card& card) {
        piles[pileName].push_back(card);
    }

    // Remove the top card from a specific pile
    Card removeTopCardFromPile(const std::string& pileName) {
        if (piles.find(pileName) != piles.end() && !piles[pileName].empty()) {
            Card topCard = piles[pileName].back();
            piles[pileName].pop_back();
            return topCard;
        } else {
            throw std::out_of_range("Pile is empty or does not exist");
        }
    }

    // Flip the top card of a specified pile to face up
    void flipTopCardInPile(const std::string& pileName) {
        if (piles.find(pileName) != piles.end() && !piles[pileName].empty()) {
            Card& topCard = piles[pileName].back();
            if (!topCard.faceUp) {
                topCard.faceUp = true;
            }
        }
    }

    // Display all cards in a specific pile
    void displayPile(const std::string& pileName) const {
        if (piles.find(pileName) != piles.end()) {
            std::cout << pileName << ": ";
            for (const auto& card : piles.at(pileName)) {
                card.display();
                std::cout << " -> ";
            }
            std::cout << "NULL" << std::endl;
        } else {
            std::cout << "Pile " << pileName << " does not exist." << std::endl;
        }
    }

    // Check if a specific pile is empty
    bool isPileEmpty(const std::string& pileName) const {
        return piles.find(pileName) == piles.end() || piles.at(pileName).empty();
    }
};

// int main() {
//     // Create a GameMap to track piles
//     GameMap gameMap;

//     // Add cards to a tableau pile (Tableau1) and a foundation pile (FoundationA)
//     gameMap.addCardToPile("Tableau1", Card("Hearts", 4, false));
//     gameMap.addCardToPile("Tableau1", Card("Spades", 10, true));
//     gameMap.addCardToPile("FoundationA", Card("Diamonds", 1, true));  // Ace of Diamonds

//     // Display the piles
//     std::cout << "Initial Piles:" << std::endl;
//     gameMap.displayPile("Tableau1");
//     gameMap.displayPile("FoundationA");

//     // Flip the top card in the tableau pile if it's face down
//     gameMap.flipTopCardInPile("Tableau1");

//     // Display the pile after flipping the top card
//     std::cout << "\nTableau1 after flipping the top card:" << std::endl;
//     gameMap.displayPile("Tableau1");

//     // Remove the top card from Tableau1
//     Card removedCard = gameMap.removeTopCardFromPile("Tableau1");
//     std::cout << "\nRemoved card from Tableau1: ";
//     removedCard.display();
//     std::cout << std::endl;

//     // Display the pile after removal
//     std::cout << "\nTableau1 after removing the top card:" << std::endl;
//     gameMap.displayPile("Tableau1");

//     // Check if FoundationA is empty
//     std::cout << "\nIs FoundationA empty? " << (gameMap.isPileEmpty("FoundationA") ? "Yes" : "No") << std::endl;

//     return 0;
// }




//Game Mechanics: Initialization 
//Shuffle the deck and deal seven tableau piles with increasing numbers of cards (1 to 7) with 
//the last card face up




#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>

// Define the Card class (same as before)
class Card {
public:
    std::string suit;
    int rank;
    bool faceUp;

    Card(std::string s, int r, bool face) : suit(s), rank(r), faceUp(face) {}

    void display() const {
        if (faceUp)
            std::cout << rank << " of " << suit;
        else
            std::cout << "Face Down";
    }
};

// Define the Deck class to manage the deck of cards
class Deck {
private:
    std::vector<Card> cards;

public:
    // Constructor to initialize and create a standard 52-card deck
    Deck() {
        std::string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
        
        // Populate the deck with cards for each suit and rank
        for (const auto& suit : suits) {
            for (int rank = 1; rank <= 13; ++rank) {  // Rank 1 to 13 (Ace to King)
                cards.push_back(Card(suit, rank, false));  // Cards start face-down
            }
        }
    }

    // Shuffle the deck
    void shuffleDeck() {
        std::srand(static_cast<unsigned>(std::time(0)));
        std::random_shuffle(cards.begin(), cards.end());
    }

    // Deal a card from the deck
    Card dealCard() {
        if (!cards.empty()) {
            Card dealtCard = cards.back();
            cards.pop_back();
            return dealtCard;
        } else {
            throw std::out_of_range("No cards left to deal");
        }
    }

    // Check if the deck is empty
    bool isEmpty() const {
        return cards.empty();
    }
};

// Define the LinkedList class to represent a tableau pile
class LinkedList {
private:
    struct Node {
        Card card;
        Node* next;
        Node(Card c) : card(c), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Add a card to the top of the pile (push front)
    void addCard(const Card& card) {
        Node* newNode = new Node(card);
        newNode->next = head;
        head = newNode;
    }

    // Display all cards in the pile (top to bottom)
    void displayPile() const {
        Node* current = head;
        while (current != nullptr) {
            current->card.display();
            std::cout << " -> ";
            current = current->next;
        }
        std::cout << "NULL" << std::endl;
    }

    // Destructor to clean up linked list nodes
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Define the Game class to handle game initialization
class Game {
private:
    Deck deck;                       // The deck of cards
    std::vector<LinkedList> tableau;  // The tableau piles

public:
    Game() {
        tableau.resize(7);  // Create 7 tableau piles
    }

    // Initialize the game by shuffling the deck and dealing cards to the tableau piles
    void initializeGame() {
        deck.shuffleDeck();

        // Deal cards to tableau piles with increasing number of cards (1 to 7)
        for (int i = 0; i < 7; ++i) {
            for (int j = 0; j <= i; ++j) {
                Card dealtCard = deck.dealCard();
                tableau[i].addCard(dealtCard);
            }
            // Make the last card face-up
            tableau[i].displayPile();
        }
    }

    // Display the tableau piles (for testing purposes)
    void displayTableau() const {
        for (int i = 0; i < tableau.size(); ++i) {
            std::cout << "Tableau " << i + 1 << ": ";
            tableau[i].displayPile();
        }
    }
};

// int main() {
//     // Create the game and initialize
//     Game solitaireGame;
//     solitaireGame.initializeGame();

//     // Display the tableau piles
//     std::cout << "\nTableau piles after initialization:\n";
//     solitaireGame.displayTableau();

//     return 0;
// }





//Moves: Implement moves between tableau piles, to the foundation, and from the stockpile. 





// Define the Foundation class to manage foundation piles
class Foundation {
private:
    std::unordered_map<std::string, std::vector<Card>> foundationPiles;

public:
    // Constructor to initialize four foundation piles, one for each suit
    Foundation() {
        foundationPiles["Hearts"] = {};
        foundationPiles["Diamonds"] = {};
        foundationPiles["Clubs"] = {};
        foundationPiles["Spades"] = {};
    }

    // Add a card to the foundation pile if it's a valid move
    bool addCardToFoundation(const Card& card) {
        // Check if the card can be added to the correct pile
        if (foundationPiles.find(card.suit) != foundationPiles.end()) {
            if (foundationPiles[card.suit].empty() && card.rank == 1) {
                // If the pile is empty, only an Ace can be added
                foundationPiles[card.suit].push_back(card);
                return true;
            } else if (!foundationPiles[card.suit].empty()) {
                Card topCard = foundationPiles[card.suit].back();
                if (topCard.rank + 1 == card.rank) {
                    foundationPiles[card.suit].push_back(card);
                    return true;
                }
            }
        }
        return false;
    }

    // Display the current state of the foundation piles
    void displayFoundation() const {
        std::cout << "Foundation:" << std::endl;
        for (const auto& suit : foundationPiles) {
            std::cout << suit.first << ": ";
            for (const auto& card : suit.second) {
                card.display();
                std::cout << " -> ";
            }
            std::cout << "NULL" << std::endl;
        }
    }
};





class Game {
private:
    Deck deck;                         // The deck of cards
    std::vector<LinkedList> tableau;    // The tableau piles
    Foundation foundation;             // The foundation piles
    std::vector<Card> stockpile;       // The stockpile of remaining cards
    int stockpileIndex;                // Index to track stockpile card drawing

public:
    Game() : stockpileIndex(0) {
        tableau.resize(7);  // Create 7 tableau piles
        stockpile = deck.cards; // Initialize stockpile with the shuffled deck
        deck.shuffleDeck();
    }

    // Initialize the game
    void initializeGame() {
        deck.shuffleDeck();
        for (int i = 0; i < 7; ++i) {
            for (int j = 0; j <= i; ++j) {
                Card dealtCard = deck.dealCard();
                tableau[i].addCard(dealtCard);
            }
            tableau[i].displayPile();
        }
    }

    // Move a card from tableau to tableau
    bool moveTableauToTableau(int from, int to) {
        if (from < 0 || from >= tableau.size() || to < 0 || to >= tableau.size()) return false;

        // Ensure the last card in the "from" tableau is face-up
        Card topCardFrom = tableau[from].removeTopCardFromPile();
        // Check for legal move: alternating colors and 1 rank lower
        if (isValidTableauMove(topCardFrom, tableau[to].getTopCard())) {
            tableau[to].addCard(topCardFrom);
            return true;
        }
        return false;
    }

    // Move a card from tableau to foundation
    bool moveTableauToFoundation(int tableauIndex) {
        if (tableauIndex < 0 || tableauIndex >= tableau.size()) return false;

        // Ensure the last card in the tableau is face-up
        Card topCard = tableau[tableauIndex].removeTopCardFromPile();

        // Add to foundation if it's a valid move
        if (foundation.addCardToFoundation(topCard)) {
            return true;
        }

        // Return the card back to tableau if the move was invalid
        tableau[tableauIndex].addCard(topCard);
        return false;
    }

    // Draw a card from the stockpile
    Card drawFromStockpile() {
        if (stockpileIndex < stockpile.size()) {
            return stockpile[stockpileIndex++];
        }
        throw std::out_of_range("Stockpile is empty");
    }

    // Display the tableau piles and stockpile
    void displayGame() {
        std::cout << "\nTableau piles:\n";
        for (int i = 0; i < tableau.size(); ++i) {
            tableau[i].displayPile();
        }
        foundation.displayFoundation();
        std::cout << "\nStockpile: " << stockpile.size() - stockpileIndex << " cards remaining.\n";
    }

private:
    // Helper function to check if the tableau move is valid
    bool isValidTableauMove(const Card& card, const Card& targetCard) {
        if (targetCard.suit.empty()) return true; // if the target card is empty (no card)
        if ((card.rank + 1 == targetCard.rank) &&
            (card.suit != targetCard.suit) && // alternating colors
            ((card.suit == "Hearts" || card.suit == "Diamonds") != (targetCard.suit == "Clubs" || targetCard.suit == "Spades"))) {
            return true;
        }
        return false;
    }
};

// int main() {
//     Game solitaireGame;
//     solitaireGame.initializeGame();
//     solitaireGame.displayGame();

//     // Example of moving cards from tableau to foundation
//     std::cout << "\nMoving card from tableau 3 to foundation:" << std::endl;
//     if (solitaireGame.moveTableauToFoundation(2)) {
//         std::cout << "Move successful!" << std::endl;
//     } else {
//         std::cout << "Move failed!" << std::endl;
//     }

//     solitaireGame.displayGame();

//     return 0;
// }




//Foundation Build foundation piles from Ace to King by suit. 




#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

class Card {
public:
    std::string suit;
    int rank;
    bool faceUp;

    Card(std::string s, int r, bool face) : suit(s), rank(r), faceUp(face) {}

    void display() const {
        if (faceUp)
            std::cout << rank << " of " << suit;
        else
            std::cout << "Face Down";
    }
};

// Define the Foundation class to manage foundation piles
class Foundation {
private:
    std::unordered_map<std::string, std::vector<Card>> foundationPiles;

public:
    // Constructor to initialize four foundation piles, one for each suit
    Foundation() {
        foundationPiles["Hearts"] = {};
        foundationPiles["Diamonds"] = {};
        foundationPiles["Clubs"] = {};
        foundationPiles["Spades"] = {};
    }

    // Add a card to the foundation pile if it's a valid move
    bool addCardToFoundation(const Card& card) {
        // Check if the card can be added to the correct pile
        if (foundationPiles.find(card.suit) != foundationPiles.end()) {
            // Check if the foundation pile for this suit is empty (Ace can be placed)
            if (foundationPiles[card.suit].empty() && card.rank == 1) {
                foundationPiles[card.suit].push_back(card);
                return true;
            } 
            // Check if the card can be placed after the top card in the foundation pile
            else if (!foundationPiles[card.suit].empty()) {
                Card topCard = foundationPiles[card.suit].back();
                if (topCard.rank + 1 == card.rank) {
                    foundationPiles[card.suit].push_back(card);
                    return true;
                }
            }
        }
        return false;
    }

    // Display the current state of the foundation piles
    void displayFoundation() const {
        std::cout << "Foundation:" << std::endl;
        for (const auto& suit : foundationPiles) {
            std::cout << suit.first << ": ";
            for (const auto& card : suit.second) {
                card.display();
                std::cout << " -> ";
            }
            std::cout << "NULL" << std::endl;
        }
    }
};





class Game {
private:
    Deck deck;                         // The deck of cards
    std::vector<LinkedList> tableau;    // The tableau piles
    Foundation foundation;             // The foundation piles
    std::vector<Card> stockpile;       // The stockpile of remaining cards
    int stockpileIndex;                // Index to track stockpile card drawing

public:
    Game() : stockpileIndex(0) {
        tableau.resize(7);  // Create 7 tableau piles
        stockpile = deck.cards; // Initialize stockpile with the shuffled deck
        deck.shuffleDeck();
    }

    // Initialize the game
    void initializeGame() {
        deck.shuffleDeck();
        for (int i = 0; i < 7; ++i) {
            for (int j = 0; j <= i; ++j) {
                Card dealtCard = deck.dealCard();
                tableau[i].addCard(dealtCard);
            }
            tableau[i].displayPile();
        }
    }

    // Move a card from tableau to foundation
    bool moveTableauToFoundation(int tableauIndex) {
        if (tableauIndex < 0 || tableauIndex >= tableau.size()) return false;

        // Ensure the last card in the tableau is face-up
        Card topCard = tableau[tableauIndex].removeTopCardFromPile();

        // Add to foundation if it's a valid move
        if (foundation.addCardToFoundation(topCard)) {
            return true;
        }

        // Return the card back to tableau if the move was invalid
        tableau[tableauIndex].addCard(topCard);
        return false;
    }

    // Display the tableau piles and stockpile
    void displayGame() {
        std::cout << "\nTableau piles:\n";
        for (int i = 0; i < tableau.size(); ++i) {
            tableau[i].displayPile();
        }
        foundation.displayFoundation();
        std::cout << "\nStockpile: " << stockpile.size() - stockpileIndex << " cards remaining.\n";
    }

    // Draw a card from the stockpile
    Card drawFromStockpile() {
        if (stockpileIndex < stockpile.size()) {
            return stockpile[stockpileIndex++];
        }
        throw std::out_of_range("Stockpile is empty");
    }
};




// int main() {
//     Game solitaireGame;
//     solitaireGame.initializeGame();
//     solitaireGame.displayGame();

//     // Example of moving cards from tableau to foundation
//     std::cout << "\nMoving card from tableau 3 to foundation:" << std::endl;
//     if (solitaireGame.moveTableauToFoundation(2)) {
//         std::cout << "Move successful!" << std::endl;
//     } else {
//         std::cout << "Move failed!" << std::endl;
//     }

//     solitaireGame.displayGame();

//     return 0;
// }




//Victory Condition The game is won when all cards are moved from the tableau and stockpile to the foundation 
//piles.





class Game {
private:
    Deck deck;                         // The deck of cards
    std::vector<LinkedList> tableau;    // The tableau piles
    Foundation foundation;             // The foundation piles
    std::vector<Card> stockpile;       // The stockpile of remaining cards
    int stockpileIndex;                // Index to track stockpile card drawing

public:
    Game() : stockpileIndex(0) {
        tableau.resize(7);  // Create 7 tableau piles
        stockpile = deck.cards; // Initialize stockpile with the shuffled deck
        deck.shuffleDeck();
    }

    // Initialize the game
    void initializeGame() {
        deck.shuffleDeck();
        for (int i = 0; i < 7; ++i) {
            for (int j = 0; j <= i; ++j) {
                Card dealtCard = deck.dealCard();
                tableau[i].addCard(dealtCard);
            }
            tableau[i].displayPile();
        }
    }

    // Move a card from tableau to foundation
    bool moveTableauToFoundation(int tableauIndex) {
        if (tableauIndex < 0 || tableauIndex >= tableau.size()) return false;

        // Ensure the last card in the tableau is face-up
        Card topCard = tableau[tableauIndex].removeTopCardFromPile();

        // Add to foundation if it's a valid move
        if (foundation.addCardToFoundation(topCard)) {
            return true;
        }

        // Return the card back to tableau if the move was invalid
        tableau[tableauIndex].addCard(topCard);
        return false;
    }

    // Draw a card from the stockpile
    Card drawFromStockpile() {
        if (stockpileIndex < stockpile.size()) {
            return stockpile[stockpileIndex++];
        }
        throw std::out_of_range("Stockpile is empty");
    }

    // Check if the foundation piles are complete (all cards in order)
    bool isFoundationComplete() const {
        // Each foundation pile should have 13 cards (Ace to King)
        for (const auto& suitPile : foundation.foundationPiles) {
            if (suitPile.second.size() != 13) {
                return false;  // Foundation pile for this suit is not complete
            }

            // Check if the cards are in order from Ace to King
            for (size_t i = 0; i < suitPile.second.size(); ++i) {
                if (suitPile.second[i].rank != (i + 1)) {
                    return false;  // The rank is not in the correct order
                }
            }
        }
        return true;
    }

    // Check if all tableau piles and the stockpile are empty, indicating the game is won
    bool isGameWon() const {
        // Check if tableau piles are empty
        for (const auto& pile : tableau) {
            if (!pile.isEmpty()) {
                return false;  // Some cards are still in tableau piles
            }
        }

        // Check if stockpile is empty
        if (stockpileIndex < stockpile.size()) {
            return false;  // Stockpile still has cards
        }

        // Check if the foundation is complete
        if (!isFoundationComplete()) {
            return false;  // Foundation is not complete
        }

        return true;  // Game is won
    }

    // Display the tableau piles, stockpile, and foundation
    void displayGame() {
        std::cout << "\nTableau piles:\n";
        for (int i = 0; i < tableau.size(); ++i) {
            tableau[i].displayPile();
        }
        foundation.displayFoundation();
        std::cout << "\nStockpile: " << stockpile.size() - stockpileIndex << " cards remaining.\n";
    }
};




// int main() {
//     Game solitaireGame;
//     solitaireGame.initializeGame();
//     solitaireGame.displayGame();

//     // Example of moving cards from tableau to foundation
//     std::cout << "\nMoving card from tableau 3 to foundation:" << std::endl;
//     if (solitaireGame.moveTableauToFoundation(2)) {
//         std::cout << "Move successful!" << std::endl;
//     } else {
//         std::cout << "Move failed!" << std::endl;
//     }

//     solitaireGame.displayGame();

//     // Check if the game is won
//     if (solitaireGame.isGameWon()) {
//         std::cout << "\nCongratulations! You've won the game!" << std::endl;
//     } else {
//         std::cout << "\nThe game is still ongoing." << std::endl;
//     }

//     return 0;
// }



