#include <iostream>
#include <string>

using namespace std;

const int BOARD_SIZE = 3;
char board[BOARD_SIZE][BOARD_SIZE];

void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isMoveValid(int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return false;
    }
    if (board[row][col] != '-') {
        return false;
    }
    return true;
}

bool checkWin(char player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

int main() {
    initializeBoard();
    char currentPlayer = 'X';
    int row, col;
    while (true) {
        printBoard();
        cout << "Player " << currentPlayer << "'s turn. Enter row and column (0-2): ";
        cin >> row >> col;
        if (isMoveValid(row, col)) {
            board[row][col] = currentPlayer;
            if (checkWin(currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }
            if (currentPlayer == 'X') {
                currentPlayer = 'O';
            } else {
                currentPlayer = 'X';
            }
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }
    printBoard();
    return 0;
}
