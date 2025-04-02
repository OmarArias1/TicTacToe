Tic-Tac-Toe Game

A simple two-player Tic-Tac-Toe game built in C++.
Table of Contents
## Table of Contents
- [Overview](#overview)
- [Files Included](#files-included)
- [Compilation & Execution](#compilation--execution)
- [Gameplay](#gameplay)
- [Features](#features)
- [Known Issues](#known-issues)
- [Credits](#credits)

## Overview

This is a console-based Tic-Tac-Toe game where two players take turns choosing positions on a 3x3 grid. The game determines the winner when a player successfully places three of their symbols in a row, column, or diagonal.

### Files Included

    tictactoe.h – Header file defining the TicTacToe class.

    tictactoe.cpp – Implementation file for the TicTacToe class, handling game logic.

    main.cpp – The entry point that initializes and runs the game.

### Compilation & Execution
Using g++

To compile and run the game:

g++ main.cpp tictactoe.cpp -o tic_tac_toe
./tic_tac_toe

Using MinGW (Windows)

g++ main.cpp tictactoe.cpp -o tic_tac_toe.exe
tic_tac_toe.exe

### Gameplay

    Players choose a character to represent them (e.g., 'X' or 'O').

    A player is chosen to go first.

    Players take turns picking a position (1-9) to place their symbol on the grid.

    The game continues until a player wins or the board is full.

    The game announces the winner or a tie.

### Features

    Two-player mode.

    Customizable player symbols.

    Randomized first player selection if not manually chosen.

    Input validation for correct move entries.

    Console-based UI.

### Known Issues

    The game currently does not handle detecting ties (i.e., when the board is full without a winner).

    Some input handling (like non-numeric values) may need improvements.

### Credits

Developed by: Omar Arias
Language: C++
