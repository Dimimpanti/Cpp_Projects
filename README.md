#  My First C++ Projects: Game Development
Welcome to my repository! Here, you'll find my initial projects created while learning C++. These projects showcase simple, yet fun, command-line games.

## About the Games

**Connect 4** is a two-player game where players take turns dropping colored discs into a vertical grid. The first player to connect four of their own discs in a row (horizontally, vertically, or diagonally) wins the game.

In this implementation, Player 1 and Player 2 are represented by two different colors—either Red (R) or Yellow (Y)—and the game is played in the terminal.

## How to Play

### Choose Colors:
- Player 1 selects a color (Red or Yellow) at the beginning of the game. Player 2 is automatically assigned the other color.
- Colors are represented by the characters 'R' and 'Y' on the board.

### Taking Turns:
- The players alternate turns, starting with Player 1.
- Each player chooses a column (from 0 to 6) to drop their disc.
- The disc will fall to the lowest available row in the chosen column.

### Winning Condition:
- The game checks for a winning condition (four consecutive discs of the same color) after each turn.
- A player wins if they connect four discs horizontally, vertically, or diagonally.

### Ending the Game:
- When a player wins, the game announces the winner and exits.

## Code Structure

### Main Functions:
- `printTable`: Prints the current game board with ASCII characters to represent the grid.
- `colorChoice`: Allows Player 1 to choose a color, assigning the other color to Player 2.
- `PlayRound`: Manages each player's turn, prompting them to choose a column and placing their disc.
- `checkWin`: Checks for any winning condition (horizontal, vertical, diagonal) for a given player after each turn.

### Variables:
- `tb[6][7]`: A 2D array representing the game board with 6 rows and 7 columns.
- `player1` and `player2`: Characters ('R' or 'Y') representing each player's color.
- `col1` and `col2`: Integers to store the column choices for each player.
