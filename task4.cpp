#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

// Constants for the game board used 
const int ROWS = 6;
const int COLS = 7;
const char EMPTY = ' ';
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

// Function to print the Game Board
void gameBoard(const vector<vector<char>>& board)
{
    system("cls");
    cout << "Welcome to CONNECT 4!\n";
    cout << "Connect 4 Game!\n\n";
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout<< "| " << board[i][j] << " "; 
        }
        cout<<"|\n";
    }
    cout << "-----------------------------\n";
    cout << "| 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n";
    cout << "-----------------------------\n";
}

// Function to check if a column is valid for a move
bool isValidMove(const vector<vector<char>>& board, int col)
{
    return (col >= 0 && col < COLS && board[0][col] == EMPTY);
}

// Function to make a move in a column 
void makeMove(vector<vector<char>> &board, int col, char player)
{
    for (int i = ROWS - 1; i >= 0; i--)
    {
        if (board[i][col] == EMPTY)
        {
            board[i][col] = player;
            break;
        }
    }
}

// Function to check if the board is full 
bool isBoardFull(const vector<vector<char>>& board)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if(board[i][j] == EMPTY)
                return false;
        }
    }
    return true;
}

// void checkWinner(const vector<vector<char>>& board)
// {
//     for (int i = 0; i < ROWS; i++)
//     {
//         for (int j = 0; j < COLS; j++)
//         {
//             if(board[i][j] == 'X' &&
//                board[i][j + 1] == 'X' &&
//                board[i][j + 2] == 'X' &&
//                board[i][j + 3] == 'X')
//             {
//                 cout<< "Player X WINS!!" << endl;
//                 // return true;
//             }
//             else if(board[i][j] == 'O' &&
//                board[i][j + 1] == 'O' &&
//                board[i][j + 2] == 'O' &&
//                board[i][j + 3] == 'O' )
//             {
//                 cout<< "Player O WINS!!" << endl;
//                 // return true;
//             }

//             if(board[i][j] == 'X' &&
//                board[i][j - 1] == 'X' &&
//                board[i][j - 2] == 'X' &&
//                board[i][j - 3] == 'X')
//             {
//                 cout<< "Player X WINS!!" << endl;
//                 // return true;
//             }
//             else if(board[i][j] == 'O' &&
//                board[i][j - 1] == 'O' &&
//                board[i][j - 2] == 'O' &&
//                board[i][j - 3] == 'O' )
//             {
//                 cout<< "Player O WINS!!" << endl;
//                 // return true;
//             }

//             if(board[i][j] == 'X' &&
//                board[i + 1][j] == 'X' &&
//                board[i + 2][j] == 'X' &&
//                board[i + 3][j] == 'X' )
//             {
//                 cout<< "Player X WINS!!" << endl;
//                 // return true;
//             }
//             else if(board[i][j] == 'O' &&
//                board[i + 1][j] == 'O' &&
//                board[i + 2][j] == 'O' &&
//                board[i + 3][j] == 'O' )
//             {
//                 cout<< "Player O WINS!!" << endl;
//                 // return true;
//             }

//             if(board[i][j] == 'X' &&
//                board[i - 1][j] == 'X' &&
//                board[i - 2][j] == 'X' &&
//                board[i - 3][j] == 'X' )
//             {
//                 cout<< "Player X WINS!!" << endl;
//                 // return true;
//             }
//             else if(board[i][j] == 'O' &&
//                board[i - 1][j] == 'O' &&
//                board[i - 2][j] == 'O' &&
//                board[i - 3][j] == 'O' )
//             {
//                 cout<< "Player O WINS!!" << endl;
//                 // return true;
//             }
            
//             if (board[i][j] == 'X' &&
//                 board[i + 1][j + 1] == 'X' &&
//                 board[i + 2][j + 2] == 'X' &&
//                 board[i + 3][j + 3] == 'X')
//             {
//                 cout << "Player X WINS" << endl;
//                 // return true;
//             }
//             else if (board[i][j] == 'O' &&
//                 board[i + 1][j + 1] == 'O' &&
//                 board[i + 2][j + 2] == 'O' &&
//                 board[i + 3][j + 3] == 'O')
//             {
//                 cout << "Player O WINS" << endl;
//                 // return true;
//             }

//             else if (board[i][i] == 'X' &&
//                 board[i - 1][j - 1] == 'X' &&
//                 board[i - 2][j - 2] == 'X' &&
//                 board[i - 3][j - 3] == 'X')
//             {
//                 cout << "Player X WINS!!" << endl;
//                 // return true;
//             }
//             else if (board[i][i] == 'O' &&
//                 board[i - 1][j - 1] == 'O' &&
//                 board[i - 2][j - 2] == 'O' &&
//                 board[i - 3][j - 3] == 'O')
//             {
//                 cout << "Player O WINS!!" << endl;
//                 // return true;
//             }

//             else if (board[i][i] == 'X' &&
//                 board[i + 1][j - 1] == 'X' &&
//                 board[i + 2][j - 2] == 'X' &&
//                 board[i + 3][j - 3] == 'X')
//             {
//                 cout << "Player X WINS!!" << endl;
//                 // return true;
//             }
//             else if (board[i][i] == 'O' &&
//                 board[i + 1][j - 1] == 'O' &&
//                 board[i + 2][j - 2] == 'O' &&
//                 board[i + 3][j - 3] == 'O')
//             {
//                 cout << "Player O WINS!!" << endl;
//                 // return true;
//             }
            
//             else if (board[i][i] == 'X' &&
//                 board[i - 1][j + 1] == 'X' &&
//                 board[i - 2][j + 2] == 'X' &&
//                 board[i - 3][j + 3] == 'X')
//             {
//                 cout << "Player X WINS!!" << endl;
//                 // return true;
//             }
//             else if (board[i][i] == 'O' &&
//                 board[i - 1][j + 1] == 'O' &&
//                 board[i - 2][j + 2] == 'O' &&
//                 board[i - 3][j + 3] == 'O')
//             {
//                 cout << "Player O WINS!!" << endl;
//                 // return true;
//             }
//         }   
//     }
//     // return false;
    
// }

int main()
{
    vector<vector<char>> board(ROWS, vector<char> (COLS, EMPTY));
    bool player1turn = true;


    while(true)
    {
        gameBoard(board);

        // checkWinner(board);
        char currentPlayer = (player1turn) ? PLAYER1 : PLAYER2;
        cout << "Player " << currentPlayer << ", Enter your move (1 - 7): ";
        int col;
        cin >> col;
        col--;

        if (isValidMove(board, col))
        {
            makeMove(board, col, currentPlayer);
            if (isBoardFull(board))
            {
                gameBoard(board);
                cout<< "It is a TIE!!";
                break;
            }
            player1turn = !player1turn;
        }
        else
        {
            cout << "Invalid move!! Try Again!!";
        }
    }
    return 0;
}
