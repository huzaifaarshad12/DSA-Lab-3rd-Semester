#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib> 
#include "Game.h"

using namespace std;



string getOption() {
    cout << "Choose an option:" << endl;
    cout << "1. Move tableau to tableau" << endl;
    cout << "2. Move tableau to foundation" << endl;
    cout << "3. Move stock to tableau" << endl;
    cout << "4. Move stock to foundation" << endl;
    cout << "5. Quit" << endl;
    string choice;
    cin >> choice;
    return choice;

}

void clearScreen() {
    #ifdef _WIN32
        system("cls");  
    #else
        system("clear"); 
    #endif
}
int main() {
    Game game;


    while (true) {
        //system("clear");  

        clearScreen();
        game.displayTableauPiles();
        game.displayFoundationPiles();
        game.displayStockPile();  

        string choice = getOption();
    if (choice == "1") {
    try {
        int sourcePile, destinationPile;
        cout << "Enter source tableau pile number: ";
        cin >> sourcePile;
        cout << "Enter destination tableau pile number: ";
        cin >> destinationPile;

        // Check if input is valid and within expected range
        if (sourcePile < 1 || sourcePile > 7 || destinationPile < 1 || destinationPile > 7) {
            cout << "Invalid pile numbers. Please enter numbers between 1 and 7." << endl;
        } else {
            game.moveTableauToTableau(sourcePile - 1, destinationPile - 1);
        }
    }
    catch (const std::invalid_argument& e) {
        cout << "Invalid input. Please enter a valid number." << endl;
    }
}
        else if (choice == "2") {
            int sourcePile, destinationPile;
            cout << "Enter source tableau pile number: ";
            cin >> sourcePile;
            cout << "Enter destination foundation pile number: ";
            cin >> destinationPile;
            game.moveTableauToFoundation(sourcePile - 1, destinationPile - 1);
        } 
        else if (choice == "3") {
            int stockIndex, destinationPile;
            cout << "Enter stock card index to move (0-23): ";
            cin >> stockIndex;
            cout << "Enter destination tableau pile number: ";
            cin >> destinationPile;
            game.moveStockToTableau(stockIndex, destinationPile - 1);
        } 
        else if (choice == "4") {
            int stockIndex, destinationPile;
            cout << "Enter stock card index to move (0-23): ";
            cin >> stockIndex;
            cout << "Enter destination foundation pile number: ";
            cin >> destinationPile;
            game.moveStockToFoundation(stockIndex, destinationPile - 1);
        } 
        else if (choice == "5") {
            break;
        }
                if (game.isWinner()) {
            cout << "Congratulations! You won!" << endl;
            break;
        }

    }

    return 0;
}
