# Game of Life
The Game of Life is a cellular automaton devised by the British mathematician John Horton Conway in 1970. It is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input. One interacts with the Game of Life by creating an initial configuration and observing how it evolves.

## Implementation
This implementation of the Game of Life is written in C and uses a two-dimensional array to represent the board. The board is initialized with zeros, and then randomly populated with live cells (represented by ones).

The game is played by iteratively applying the following rules to each cell:
- If a live cell has fewer than two live neighbors, it dies due to underpopulation.
- If a live cell has two or three live neighbors, it continues to live.
- If a live cell has more than three live neighbors, it dies due to overpopulation.
- If a dead cell has exactly three live neighbors, it becomes alive through reproduction.

Underpopulation: Too few live neighbors can lead to the death of a live cell.
Balanced State: Two or three live neighbors maintain the life of a live cell.
Overpopulation: More than three live neighbors can cause the death of a live cell.
Reproduction: A dead cell with exactly three live neighbors becomes alive in the next generation.

->The program uses the following functions:
void initialize(int\*\* arr, int rows, int cols): Initializes the 2D array with zeros.
void print_board(int\*\* arr, int rows, int cols): Prints the 2D array (board).
int count_neighbors(int\*\* arr, int rows, int cols, int row, int col): Counts the number of live neighbors around a cell.
void game_of_life(int\*\* arr, int rows, int cols): Simulates one generation in the Game of Life.
The `initialize` function takes a two-dimensional array, the number of rows, and the number of columns as input and initializes all the elements of the array to 0. This function is used to initialize the board before the start of the game and to reset the board after each generation.


Introduction and Rules Explanation:
The project starts with a welcome message and an introduction to the rules of the Game of Life.
It outlines the four rules governing the state of cells: underpopulation, survival, overpopulation, and reproduction.

1)Main Functionality:
The main functionality of the program is implemented in the game_of_life function.
It initializes a 2D array to represent the game board, where each element is a cell.
The program then runs a specified number of generations, updating the board according to the rules of the Game of Life in each iteration.

2)Board Initialization:
The user is prompted to enter the size of the board (number of rows and columns).
Memory is dynamically allocated for the board, and it is initialized with random values (0 or 1) to represent the initial state of the cells.

3)Generation Simulation:
The simulation progresses by applying the rules to each cell in the board.
The count_neighbors function is used to determine the number of live neighbors around each cell.
Based on the rules, cells may die, survive, or be born in each generation.

4)User Interaction:
The user is prompted to enter the number of generations they want to simulate.
After the simulation, the program prints both the initial and final boards, showing the evolution of the cellular automaton over the specified number generations.

5)Memory Management:
Dynamic memory allocation is used to create and free memory for the game board and the new board used in each generation.
Memory is appropriately freed to avoid memory leaks.
