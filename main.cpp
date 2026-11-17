
#include <iostream>
using namespace std;

// Function to display the game board
void displayBoard(char board[]) {
    cout << "\n";
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
    cout << "\n";
}

// Function to check for a winner
bool checkWinner(char board[], char player) {
    int wins[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };

    for (int i = 0; i < 8; i++) {
        if (board[wins[i][0]] == player &&
            board[wins[i][1]] == player &&
            board[wins[i][2]] == player) {
            return true;
        }
    }

    return false;
}

int main() {
    char board[9] = {'1', '2', '3', '4', '5',
                     '6', '7', '8', '9'};

    char currentPlayer = 'X';
    int choice;
    int moves = 0;

    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "Player 1: X" << endl;
    cout << "Player 2: O" << endl;

    while (moves < 9) {
        displayBoard(board);

        cout << "Player " << currentPlayer;
        cout << ", choose a position (1-9): ";
        cin >> choice;

        // Check whether the position is valid
        if (choice < 1 || choice > 9 ||
            board[choice - 1] == 'X' ||
            board[choice - 1] == 'O') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        // Place the player's mark
        board[choice - 1] = currentPlayer;
        moves++;

        // Check whether the current player has won
        if (checkWinner(board, currentPlayer)) {
            displayBoard(board);
            cout << "Congratulations! Player "
                 << currentPlayer << " wins!" << endl;
            return 0;
        }

        // Switch players
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    }

    displayBoard(board);
    cout << "It's a draw! Nobody wins." << endl;

    return 0;
}
