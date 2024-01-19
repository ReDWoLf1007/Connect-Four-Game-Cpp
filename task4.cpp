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

int CheckFour (const vector<vector<char>>& board, char activePlayer)
{
	char XO;
	int win;
	XO = activePlayer;
	win = 0;
	for(int i = ROWS - 1; i >= 0; i--)
    {		
			for(int ix = COLS - 1; ix >= 0; ix--)
            {
            if( board[i][ix] == XO     &&
				board[i-1][ix-1] == XO &&
				board[i-2][ix-2] == XO &&
				board[i-3][ix-3] == XO )
			{
				win = 1;
			}
			

			if( board[i][ix] == XO   &&
				board[i][ix-1] == XO &&
				board[i][ix-2] == XO &&
				board[i][ix-3] == XO )
			{
				win = 1;
			}
					
			if( board[i][ix] == XO   &&
				board[i-1][ix] == XO &&
				board[i-2][ix] == XO &&
				board[i-3][ix] == XO )
			{	
				win = 1;
			}
					
			if( board[i][ix] == XO     &&
				board[i-1][ix+1] == XO &&
				board[i-2][ix+2] == XO &&
				board[i-3][ix+3] == XO )
			{
				win = 1;
			}
						
			if ( board[i][ix] == XO   &&
				 board[i][ix+1] == XO &&
				 board[i][ix+2] == XO &&
				 board[i][ix+3] == XO )
			{
				win = 1;
			}
            }
    }
    return win;
}


int main()
{
    vector<vector<char>> board(ROWS, vector<char> (COLS, EMPTY));
    bool player1turn = true;

    
    while(true)
    {
        
        gameBoard(board);

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
        int w = CheckFour(board, currentPlayer);
            if(w == 1)
            {
                gameBoard(board);
                cout<<"Player "<< currentPlayer << " WINS!"<<endl;
                system("pause");
                break;
            }
    }
    return 0;
}