#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printTicTacToe(const vector<char>& values) {
    cout << "\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << values[0] << "  |  " << values[1] << "  |  " << values[2] << "\n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << values[3] << "  |  " << values[4] << "  |  " << values[5] << "\n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << values[6] << "  |  " << values[7] << "  |  " << values[8] << "\n";
    cout << "\t     |     |     \n\n";
}

void printScoreboard(const string& player1, const string& player2, int score1, int score2) {
    cout << "\t--------------------------------\n";
    cout << "\t              SCOREBOARD       \n";
    cout << "\t--------------------------------\n";
    cout << "\t   " << player1 << " \t    " << score1 << "\n";
    cout << "\t   " << player2 << " \t    " << score2 << "\n";
    cout << "\t--------------------------------\n\n";
}

bool checkWin(const vector<int>& playerPos, const vector<vector<int>>& winComb) {
    for (auto& combination : winComb) {
        if (playerPos[combination[0]] && playerPos[combination[1]] && playerPos[combination[2]]) {
            return true;
        }
    }
    return false;
}

bool checkDraw(const vector<char>& values) {
    for (char c : values) {
        if (c == ' ') {
            return false;
        }
    }
    return true;
}

void singleGame(string& curPlayer, vector<int>& playerPosX, vector<int>& playerPosO, vector<char>& values) {
    int move;
    while (true) {
        printTicTacToe(values);
        cout << "Player " << curPlayer << " turn. Which box? (1-9): ";
        cin >> move;

        if (move < 1 || move > 9 || values[move - 1] != ' ') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        values[move - 1] = curPlayer[0];
        if (curPlayer == "X") {
            playerPosX[move - 1] = 1;
        } else {
            playerPosO[move - 1] = 1;
        }

        vector<vector<int>> winComb = {
            {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}
        };
        if (curPlayer == "X" && checkWin(playerPosX, winComb)) {
            printTicTacToe(values);
            cout << "Player X wins!\n";
            break;
        } else if (curPlayer == "O" && checkWin(playerPosO, winComb)) {
            printTicTacToe(values);
            cout << "Player O wins!\n";
            break;
        }

        if (checkDraw(values)) {
            printTicTacToe(values);
            cout << "The game is a draw.\n";
            break;
        }

        curPlayer = (curPlayer == "X") ? "O" : "X";
    }
}

int main() {
    string player1, player2, curPlayer;
    int score1 = 0, score2 = 0;
    vector<char> values(9, ' ');

    cout << "Player 1, enter your name: ";
    cin >> player1;
    cout << "Player 2, enter your name: ";
    cin >> player2;

    curPlayer = player1;

    while (true) {
        printScoreboard(player1, player2, score1, score2);

        cout << "Turn for " << curPlayer << ":\n";
        cout << "Enter 1 to play with X\n";
        cout << "Enter 2 to play with O\n";
        cout << "Enter 3 to quit\n";

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "You have chosen X\n";
            vector<int> playerPosX(9, 0), playerPosO(9, 0);
            singleGame(curPlayer, playerPosX, playerPosO, values);
            score1++;
        } else if (choice == 2) {
            cout << "You have chosen O\n";
            vector<int> playerPosX(9, 0), playerPosO(9, 0);
            singleGame(curPlayer, playerPosX, playerPosO, values);
            score2++;
        } else if (choice == 3) {
            cout << "Final Scores\n";
            printScoreboard(player1, player2, score1, score2);
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }

        curPlayer = (curPlayer == player1) ? player2 : player1;
    }

    return 0;
}
