#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize the 2D array with zeros
void initialize(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = 0;
        }
    }
}

// Function to print the 2D array (board)
void print_board(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Function to count the number of live neighbors around a cell
int count_neighbors(int** arr, int rows, int cols, int row, int col) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i < 0 || i >= rows || j < 0 || j >= cols) {
                continue; // Skip if the neighbor is outside the board
            }
            if (i != row || j != col) {
                count += arr[i][j];
            }
        }
    }
    return count;
}

// Function to simulate one generation in the Game of Life
void game_of_life(int** arr, int rows, int cols) {
    // Create a new board to store the next generation
    int** new_board = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        new_board[i] = (int*)malloc(cols * sizeof(int));
    }
    // Initialize the new board with zeros
    initialize(new_board, rows, cols);

    // Update each cell based on the rules of the Game of Life
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = count_neighbors(arr, rows, cols, i, j);
            if (arr[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_board[i][j] = 0; // Cell dies due to underpopulation or overpopulation
            } else if (arr[i][j] == 0 && neighbors == 3) {
                new_board[i][j] = 1; // Cell becomes alive through reproduction
            } else {
                new_board[i][j] = arr[i][j]; // Cell remains unchanged
            }
        }
    }

    // Copy the new board back to the original board
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = new_board[i][j];
        }
    }

    // Free the memory allocated for the new board
    for (int i = 0; i < rows; i++) {
        free(new_board[i]);
    }
    free(new_board);
}

// Main function
int main() {
    // Print welcome message and rules
    printf("\nWELCOME to Game of life !!!\n");
    printf("Rules for game of life :\n");
    printf("1. If a live cell has fewer than two live neighbors, it dies due to underpopulation.\n");
    printf("2. If a live cell has two or three live neighbors, it continues to live.\n");
    printf("3. If a live cell has more than three live neighbors, it dies due to overpopulation.\n");
    printf("4. If a dead cell has exactly three live neighbors, it becomes alive through reproduction\n");

    int ch;
    int rows, cols;

    // Game loop
    do {
        printf("Please enter your choice:\n");
        printf("1. To continue playing the game\n");
        printf("2. To exit the game\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                // Get the size of the board from the user
                printf("Enter the size of the board: ");
                scanf("%d %d", &rows, &cols);

                // Allocate memory for the board and initialize it
                int** board = (int**)malloc(rows * sizeof(int*));
                for (int i = 0; i < rows; i++) {
                    board[i] = (int*)malloc(cols * sizeof(int));
                }
                initialize(board, rows, cols);

                // Randomly populate the board
                srand(time(0));
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        board[i][j] = rand() % 2;
                    }
                }

                // Print the initial board
                printf("Initial board:\n");
                print_board(board, rows, cols);

                // Get the number of generations from the user
                int generations;
                printf("Enter the number of generations: ");
                scanf("%d", &generations);

                // Simulate the specified number of generations
                for (int i = 0; i < generations; i++) {
                    game_of_life(board, rows, cols);
                }

                // Print the final board after the specified number of generations
                printf("Final board after %d generations:\n", generations);
                print_board(board, rows, cols);

                // Free the memory allocated for the board
                for (int i = 0; i < rows; i++) {
                    free(board[i]);
                }
                free(board);

                break;
            case 2:
                printf("Thanks for playing...");
                break;
            default:
                printf("Invalid input!! Please enter either 1 or 2");
        }
    } while (ch != 2);

    return 0;
}
