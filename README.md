# Connect-Four-Game-Cpp
Connect four is a unique structured game that works almost like a Tic Tac Toe game.
Player have to connect FOUR consecutive Dots to win.
If all the dots are filled it is a draw.
It is a little complex game than TIC TAC TOE in terms of codding as it requires more definitions and conditions to win.
It requires to check for the win condition with each move and with each moved position on the board.
# Functions Involved:
## gameBoard()
This function was designed to create the game board where the players would play the game.
Each iteration will call the **gameboard()** function and it will present throughout.
The game board looks like this:

##### Game Board
![Game Board](https://github.com/ReDWoLf1007/Connect-Four-Game-Cpp/blob/main/Images/board.png?)

The board will look something like this.
## isValidMove()
This function will check if the box where player wants to move is empty or is already occupied.
It will send a signal if it is valid to move there.
## makeMove()
This function will move the current player's sign(X, O) in one of the columns given by the Player.
First turn is X's turn by default, it would look something like this-

##### X's Turn
![X's turn](https://github.com/ReDWoLf1007/Connect-Four-Game-Cpp/blob/main/Images/X's%20Turn.png)

##### O's Turn
![O's Turn](https://github.com/ReDWoLf1007/Connect-Four-Game-Cpp/blob/main/Images/O's%20Turn.png)

After implying few MOVES the Board will look something like this-

##### After some Moves
![After some Moves](https://github.com/ReDWoLf1007/Connect-Four-Game-Cpp/blob/main/Images/After%20some%20moves.png)

## isBoardFull()
This Function will check of the board is full or not. If the board is full, the game will result in Draw otherwise next move is played.

##### Full Board/Tie
![Full Board](https://github.com/ReDWoLf1007/Connect-Four-Game-Cpp/blob/main/Images/Tie.png)

## checkFour()
This function will check the condition for four consecutive same signs(X, O).
If X are present in consecutive order in four of the below ways-
1. Linear / Horizontal
2. Vertical
3. Left Diagnal
4. Right Diagnal
Then X Wins.

##### X WINS
##### Linear / Horizontal WIN
![Linear](https://github.com/ReDWoLf1007/Connect-Four-Game-Cpp/blob/main/Images/Linear%20Win.png)

##### Vertical WIN
![Vertical](https://github.com/ReDWoLf1007/Connect-Four-Game-Cpp/blob/main/Images/Vertical%20Win.png)

##### Left Diagnal
![Diagnal Left](https://github.com/ReDWoLf1007/Connect-Four-Game-Cpp/blob/main/Images/Diagnal%20Left.png)

##### Right Diagnal
![Diagnal Right](https://github.com/ReDWoLf1007/Connect-Four-Game-Cpp/blob/main/Images/Diagnal%20Right.png)

Similarly Player O can win.
