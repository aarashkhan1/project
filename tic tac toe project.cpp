#include <iostream>
using namespace std;
void displayBoard(char board[]) {
    cout << "\n";
    for (int i = 0; i < 9; i++) {
        cout << " " << board[i] << " ";
        if ((i + 1) % 3 == 0) {
            cout << "\n";
            if (i < 6) cout << "---|---|---\n";
        } else {
            cout << "|";
        }
    }
    cout << "\n";
}
bool checkWin(char board[], char player) {
    int winCombos[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}             
    };
    for (int i = 0; i < 8; i++) {
        if (board[winCombos[i][0]] == player &&
            board[winCombos[i][1]] == player &&
            board[winCombos[i][2]] == player) {
            return true;
        }
    }
    return false;
}
bool isDraw(char board[]) {
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return false;
        }
    }
    return true;
}
void makeMove(char board[], char player) {
    int move;
    bool validMove = false;
    while (!validMove) {
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> move;
        if (move >= 1 && move <= 9 && board[move - 1] != 'X' && board[move - 1] != 'O') {
            board[move - 1] = player;
            validMove = true;
        } else {
            cout << "Invalid move! Try again.\n";
        }
    }
}
int main() {
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char currentPlayer = 'X';
    bool gameRunning = true;
    cout << "Welcome to Tic Tac Toe!\n";
    cout << "Player 1 is X and Player 2 is O.\n\n";
    while (gameRunning) {
        displayBoard(board);
        makeMove(board, currentPlayer);
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins! Congratulations!\n";
            gameRunning = false;
        }
        else if (isDraw(board)) {
            displayBoard(board);
            cout << "It's a draw! Well played both!\n";
            gameRunning = false;
        }
        else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
    return 0;
}
