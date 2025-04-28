//Phase 2: Tableau 
//and Foundation 
//Design the tableau and foundation piles using stacks and linked lists. Implement card 
//movement  
//functions. 




#include <iostream>
#include <stack>
#include <vector>
#include <stdexcept>

// Forward declaration of Card class
class Card;

// Foundation Pile (using a stack for each suit)
class FoundationPile {
public:
    std::stack<Card> pile;

    // Check if the foundation can accept a card (sequential and by suit)
    bool canPlaceCard(Card card);
    void placeCard(Card card);
};

// Tableau Pile (using a stack for each tableau pile)
class TableauPile {
public:
    std::stack<Card> pile;

    // Method to add a card to the tableau pile
    void addCard(Card card);
    // Method to remove the top card from the tableau pile
    Card removeCard();
    // Display the tableau pile
    void displayPile() const;
};

// Card Class (simplified for the movement operations)
class Card {
public:
    std::string suit;
    int rank;
    bool faceUp;

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
};

// FoundationPile Methods

bool FoundationPile::canPlaceCard(Card card) {
    if (pile.empty()) {
        return card.rank == 1; // Foundation starts with Ace
    }
    Card topCard = pile.top();
    // Cards must be sequential and of the same suit
    return (topCard.suit == card.suit && topCard.rank == card.rank - 1);
}

void FoundationPile::placeCard(Card card) {
    if (canPlaceCard(card)) {
        pile.push(card);
    } else {
        throw std::invalid_argument("Cannot place this card on the foundation pile.");
    }
}

// TableauPile Methods

void TableauPile::addCard(Card card) {
    pile.push(card);
}

Card TableauPile::removeCard() {
    if (pile.empty()) {
        throw std::out_of_range("No card to remove from tableau pile.");
    }
    Card topCard = pile.top();
    pile.pop();
    return topCard;
}

void TableauPile::displayPile() const {
    std::stack<Card> temp = pile;
    while (!temp.empty()) {
        temp.top().display();
        std::cout << std::endl;
        temp.pop();
    }
}

// Example of how to use Tableau and Foundation

int main() {
    // Initialize tableau and foundation piles
    std::vector<TableauPile> tableau(7); // 7 tableau piles
    std::vector<FoundationPile> foundation(4); // 4 foundation piles (one for each suit)

    // Initialize some sample cards for testing
    Card card1("Hearts", 1, true); // Ace of Hearts
    Card card2("Hearts", 2, true); // 2 of Hearts
    Card card3("Spades", 1, true); // Ace of Spades
    Card card4("Diamonds", 1, true); // Ace of Diamonds

    // Add cards to tableau piles for testing
    tableau[0].addCard(card1);
    tableau[1].addCard(card2);
    tableau[2].addCard(card3);
    tableau[3].addCard(card4);

    // Move a card to foundation
    try {
        foundation[0].placeCard(card1);  // Should succeed (Ace of Hearts to foundation)
        foundation[0].placeCard(card2);  // Should succeed (2 of Hearts to foundation)
        foundation[1].placeCard(card3);  // Should succeed (Ace of Spades to foundation)
        foundation[2].placeCard(card4);  // Should succeed (Ace of Diamonds to foundation)
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Display tableau and foundation piles
    std::cout << "Tableau Piles:" << std::endl;
    for (int i = 0; i < tableau.size(); ++i) {
        std::cout << "Pile " << i + 1 << ": ";
        tableau[i].displayPile();
        std::cout << std::endl;
    }

    std::cout << "Foundation Piles:" << std::endl;
    for (int i = 0; i < foundation.size(); ++i) {
        std::cout << "Foundation " << i + 1 << ": ";
        if (!foundation[i].pile.empty()) {
            foundation[i].pile.top().display();
        } else {
            std::cout << "Empty";
        }
        std::cout << std::endl;
    }

    return 0;
}
