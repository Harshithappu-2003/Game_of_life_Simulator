# Game of Life Simulator

A C program that simulates Conway's Game of Life.

## Description

The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970. It consists of a grid of cells that evolve through discrete time steps according to a set of simple rules.

This project is a simulation of Conway's Game of Life implemented in C. The program allows users to initialize a board with random states and then simulate multiple generations based on the game's rules.

## Rules

1. **Underpopulation:** If a live cell has fewer than two live neighbors, it dies.
2. **Survival:** If a live cell has two or three live neighbors, it continues to live.
3. **Overpopulation:** If a live cell has more than three live neighbors, it dies.
4. **Reproduction:** If a dead cell has exactly three live neighbors, it becomes alive.

## Features

- **Initialization:** The board is initialized with random states (live or dead).
- **Simulation:** The board evolves through generations based on the rules of the game.
- **Dynamic Size:** The board size can be specified by the user.
- **Multiple Generations:** The number of generations to simulate can be specified by the user.

## Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/yourusername/Game-of-Life-Simulator.git
2. # Navigate to the project directory:
   cd Game-of-Life-Simulator

3. # Compile the program:
   gcc -o game_of_life game_of_life.c

4. # Run the Program
   ./game_of_life
   
Usage:
1.Start the program: Run the compiled executable.
2.Choose to continue or exit: Enter 1 to continue playing or 2 to exit the game.
3.Enter board size: When prompted, enter the number of rows and columns for the board.
4.Enter number of generations: When prompted, enter the number of generations to simulate.
5.View results: The initial board and the final board after the specified number of generations will be displayed.
