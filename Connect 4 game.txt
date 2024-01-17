#include <iostream>
#include <vector>

using namespace std;

// Constants for the game board
const int ROWS = 6;
const int COLS = 7;
const char EMPTY = ' ';
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

// Function to print the game board
void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|\n";
    }
    cout << "-----------------------------\n";
    cout << "| 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n";
    cout << "-----------------------------\n";
}

// Function to check if a column is valid for a move
bool isValidMove(const vector<vector<char>>& board, int col) {
    return col >= 0 && col < COLS && board[0][col] == EMPTY;
}

// Function to make a move in a column
void makeMove(vector<vector<char>>& board, int col, char player) {
    for (int i = ROWS - 1; i >= 0; --i) {
        if (board[i][col] == EMPTY) {
            board[i][col] = player;
            break;
        }
    }
}

// Function to check if the board is full
bool isBoardFull(const vector<vector<char>>& board) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (board[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(ROWS, vector<char>(COLS, EMPTY));
    bool player1Turn = true;

    cout << "Welcome to Connect 4!\n";

    while (true) {
        printBoard(board);

        char currentPlayer = (player1Turn) ? PLAYER1 : PLAYER2;
        cout << "Player " << currentPlayer << ", enter your move (1-7): ";
        
        int col;
        cin >> col;
        col--; // Convert to 0-based indexing
        
        if (isValidMove(board, col)) {
            makeMove(board, col, currentPlayer);
            if (isBoardFull(board)) {
                printBoard(board);
                cout << "It's a tie!\n";
                break;
            }
            player1Turn = !player1Turn; // Switch players
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }

    return 0;
}