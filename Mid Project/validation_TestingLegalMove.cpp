//Validation and Testing 
//Legal Moves Ensure only legal moves are made (alternating colors, sequential ranks). 




//Card Color Helper Function
//This function will determine the color of a card based on its suit:

//Red suits: Hearts (♥) and Diamonds (♦)
//Black suits: Spades (♠) and Clubs (♣)
//cpp
//Copy code
enum Suit {Spades, Hearts, Diamonds, Clubs};

class Card {
public:
    Suit suit;
    int rank;
    bool faceUp;

    Card(Suit s, int r, bool face) : suit(s), rank(r), faceUp(face) {}

    // Helper to get card color
    bool isRed() const {
        return (suit == Hearts || suit == Diamonds);
    }

    bool isBlack() const {
        return (suit == Spades || suit == Clubs);
    }

    void display() const {
        // Display the card (same as before)
    }
};






//Legal Move for Tableau-to-Tableau
//For a move between two tableau piles, we check if:

//The card to move must be one rank less than the card it’s being placed on.
//The color of the card to move must alternate from the card in the destination pile.
//cpp
//Copy code

// Validate move between tableau piles (Alternating colors and Sequential ranks)
bool Game::validateMoveTableau(int source, int dest) const {
    if (tableau[source].pile.empty()) return false; // No card to move from source pile

    Card sourceCard = tableau[source].pile.top();
    if (tableau[dest].pile.empty()) return true; // Any card can be placed on an empty tableau pile

    Card destCard = tableau[dest].pile.top();

    // Check if the source card rank is one less than the destination card rank
    if (sourceCard.rank != destCard.rank - 1) {
        return false; // Cards are not sequential
    }

    // Check for alternating colors
    if (sourceCard.isRed() == destCard.isRed()) {
        return false; // The colors are not alternating
    }

    return true;
}





//Legal Move for Tableau-to-Foundation
//When moving a card from a tableau pile to a foundation pile, we check if:

//The card is the correct rank and suit for the foundation pile (Ace to King, by suit).
//The foundation pile can only contain cards that follow the correct order (Ace → King).
//cpp
//Copy code


// Validate move from tableau to foundation pile
bool Game::validateMoveToFoundation(int tableauIndex, int foundationIndex) const {
    if (tableau[tableauIndex].pile.empty()) return false; // No card to move from tableau pile

    Card cardToMove = tableau[tableauIndex].pile.top();

    // Check if foundation pile is empty and if the card is an Ace (Ace starts the foundation)
    if (foundation[foundationIndex].pile.empty()) {
        return (cardToMove.rank == 1); // Only Ace can be placed on an empty foundation
    }

    Card topFoundationCard = foundation[foundationIndex].pile.top();

    // Check if the card is one rank higher and of the same suit as the top foundation card
    if (cardToMove.rank == topFoundationCard.rank + 1 && cardToMove.suit == topFoundationCard.suit) {
        return true;
    }

    return false;
}





//Testing the Move Validations
//Now, let's incorporate testing for move validation. We can test the legal moves by creating some cards, adding them to the tableau piles, and attempting to make moves.

//Example Test Cases
//cpp
//Copy code
void testLegalMoves() {
    // Create some cards for testing
    Card card1(Hearts, 5, true); // Red 5
    Card card2(Spades, 6, true); // Black 6
    Card card3(Clubs, 4, true);  // Black 4
    Card card4(Diamonds, 7, true); // Red 7

    // Create tableau piles and add cards
    tableau[0].addCard(card1);
    tableau[1].addCard(card2);
    tableau[2].addCard(card3);

    // Validate moves between tableau piles
    cout << "Move from tableau 0 to 1: " 
         << (validateMoveTableau(0, 1) ? "Legal" : "Illegal") << endl;

    cout << "Move from tableau 1 to 2: " 
         << (validateMoveTableau(1, 2) ? "Legal" : "Illegal") << endl;
}

void testFoundationMove() {
    // Create foundation pile and add an Ace of Hearts
    foundation[0].placeCard(Card(Hearts, 1, true));

    // Create tableau pile and add a 2 of Hearts (valid for move to foundation)
    tableau[0].addCard(Card(Hearts, 2, true));

    cout << "Move from tableau 0 to foundation 0: " 
         << (validateMoveToFoundation(0, 0) ? "Legal" : "Illegal") << endl;
}



I//ntegrating the Validations into the Game Flow
//When the player makes a move (via user input), we will use the validation functions to check if the move is legal. If not, we display an error message and don’t perform the move.

//For example, modifying moveCardBetweenTableau() to incorporate validation:

//cpp
//Copy code
void Game::moveCardBetweenTableau(int source, int dest) {
    if (!validateMoveTableau(source, dest)) {
        cout << "Invalid move between tableau piles. Please follow the alternating color and rank order rules." << endl;
        return;
    }

    Card movedCard = tableau[source].removeCard();
    tableau[dest].addCard(movedCard);

    // Record the move for undo functionality
    moveHistory.push_back(Move(true, source, dest, movedCard));
}
