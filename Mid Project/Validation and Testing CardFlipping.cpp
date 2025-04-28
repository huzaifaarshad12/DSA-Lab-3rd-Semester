//Validation and testing :Card Flipping Test card flipping after a card is moved from a tableau pile. 



//1. Add Card Flipping to Tableau Class
//The Tableau class should handle the flipping of cards when necessary. Here's how to modify the Tableau class:

//cpp
//Copy code
class Tableau {
public:
    stack<Card> pile; // Stack of cards representing a tableau pile

    // Add a card to the tableau pile
    void addCard(const Card& card) {
        pile.push(card);
    }

    // Remove a card from the tableau pile
    Card removeCard() {
        if (pile.empty()) {
            throw runtime_error("Cannot remove card from an empty pile.");
        }

        Card topCard = pile.top();
        pile.pop();

        // After removing a card, flip the next card (if any) to face-up
        if (!pile.empty()) {
            Card nextTopCard = pile.top();
            nextTopCard.faceUp = true;  // Flip the card face-up
            pile.pop();
            pile.push(nextTopCard);
        }

        return topCard;
    }

    // Display the top card of the tableau pile (for testing)
    void displayTopCard() const {
        if (!pile.empty()) {
            cout << "Top card: ";
            pile.top().display();
        } else {
            cout << "No cards in the tableau." << endl;
        }
    }
};





//Explanation:
//removeCard(): When a card is removed from the tableau, we check if there are any remaining cards in the pile. If so, the card below the one being moved is flipped face-up.
//displayTopCard(): Displays the top card of the tableau pile, helpful for testing.
//2. Modify the Move Logic to Trigger Flipping
//When a card is moved between tableau piles or to the foundation, we need to ensure the tableau pile that has been emptied (if applicable) or altered will correctly flip the next card.

//For example, in the moveCardBetweenTableau() method:

//cpp
//Copy code
void Game::moveCardBetweenTableau(int source, int dest) {
    if (!validateMoveTableau(source, dest)) {
        cout << "Invalid move between tableau piles. Please follow the alternating color and rank order rules." << endl;
        return;
    }

    // Move card from source tableau pile to destination tableau pile
    Card movedCard = tableau[source].removeCard();
    tableau[dest].addCard(movedCard);

    // After moving a card, flip the next card from the source tableau pile if any
    if (!tableau[source].pile.empty()) {
        Card nextCard = tableau[source].pile.top();
        nextCard.faceUp = true;  // Ensure the card is face-up
        tableau[source].pile.pop();
        tableau[source].pile.push(nextCard);
    }

    // Record the move for undo functionality
    moveHistory.push_back(Move(true, source, dest, movedCard));
};
