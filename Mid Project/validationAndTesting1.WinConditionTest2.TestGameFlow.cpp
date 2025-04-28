//Check Win condition implementation
//Win Condition Verify that the game correctly identifies when the player has won.



bool Game::checkWinCondition() {
    // Check if all foundation piles are complete (Ace to King for each suit)
    for (int i = 0; i < 4; ++i) { // 4 foundation piles (one for each suit)
        if (foundation[i].pile.size() != 13) {
            return false; // Foundation pile is not complete
        }

        // Verify cards are in correct sequence (Ace to King)
        Card previousCard = foundation[i].pile.top();
        if (previousCard.rank != 13) {
            return false; // Foundation pile doesn't contain King as the last card
        }

        // Check if foundation pile has sequential cards in order
        for (int j = 12; j > 0; --j) { // Start checking from King to Ace
            Card currentCard = foundation[i].pile.top();
            if (currentCard.rank != j) {
                return false; // Cards are not in sequential order
            }
            foundation[i].pile.pop();
        }
    }

    // Check if tableau and stockpile are empty
    bool tableauEmpty = true;
    for (int i = 0; i < 7; ++i) {
        if (!tableau[i].pile.empty()) {
            tableauEmpty = false;
            break;
        }
    }

    bool stockpileEmpty = stockpile.empty(); // Check if stockpile is empty

    // If both tableau and stockpile are empty and foundation piles are complete
    return tableauEmpty && stockpileEmpty;
}



//Triggering the win condition

void Game::updateGameState() {
    if (checkWinCondition()) {
        cout << "Congratulations! You have won the game!" << endl;
        // Additional actions like stopping the game, offering to restart, etc.
    }
}





//Game Flow Test the flow from initialization to game completion to ensure rules are followed.

void testGameFlow() {
    // Initialize the game
    Game game;
    game.initializeGame();  // Initializes and deals the tableau, stockpile, etc.

    // Test that the deck is shuffled and tableau piles are dealt correctly
    cout << "Initial tableau and foundation state:" << endl;
    game.displayState();

    // Test moving cards (assuming the move functions work)
    game.moveCardBetweenTableau(0, 1); // Move card from tableau 0 to tableau 1
    game.moveCardToFoundation(0, 0);  // Move card from tableau 0 to foundation 0

    // Test that the game correctly identifies a win
    while (!game.checkWinCondition()) {
        // Continue making moves until the game is won (this is just a simulation)
        game.moveCardBetweenTableau(1, 2);
        game.moveCardToFoundation(1, 1);
        // Add more moves here as necessary

        // Periodically check for win condition
        if (game.checkWinCondition()) {
            cout << "Game over: You won!" << endl;
            break;
        }
    }

    // Display the final state after the game ends
    game.displayState();
}