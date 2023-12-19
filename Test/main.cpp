#include <iostream>
#include <windows.h>
#include "SudokuSolver.h"

void setColor(int textColor, int bgColor = 7) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor | (bgColor << 5));
}

// Function to reset text color to default
void resetColor() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 7 is the default color code
}
void setBald() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 15 is the bald code
}

int main() {
    setBald();
    printf("Welcome to Sudoku Solver!\n\n");

    // Classic Sudoku Example
    std::vector<std::vector<char>> classicBoard = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    SudokuSolver::safeSolve(classicBoard);

    // Print the result or indicate if it's invalid
    if (classicBoard.empty()) {
        printf("Invalid Classic Sudoku\n");
    } else {
        printf("Classic Sudoku Solution:\n  ");
        resetColor();
        for (const auto& row : classicBoard) {
            setColor(0);
            printf(" ");
            for (char cell : row) {
                printf("%c ", cell);
            }
            resetColor();
            printf("\n  ");
        }
        printf("\n");
    }

    // Example typeGrid
    std::vector<std::vector<unsigned char>> typeGrid = {
            {0, 0, 0, 1, 2, 2, 2, 2, 2},
            {0, 0, 0, 1, 1, 1, 2, 2, 2},
            {0, 3, 3, 3, 3, 1, 1, 1, 2},
            {0, 0, 3, 4, 4, 4, 4, 1, 1},
            {3, 3, 3, 3, 4, 5, 5, 5, 5},
            {6, 6, 4, 4, 4, 4, 5, 7, 7},
            {8, 6, 6, 6, 5, 5, 5, 5, 7},
            {8, 8, 8, 6, 6, 6, 7, 7, 7},
            {8, 8, 8, 8, 8, 6, 7, 7, 7}
    };

    std::vector<std::vector<char>> board = {
            {'3', '.', '.', '.', '.', '.', '.', '.', '4'},
            {'.', '.', '2', '.', '6', '.', '1', '.', '.'},
            {'.', '1', '.', '9', '.', '8', '.', '2', '.'},
            {'.', '.', '5', '.', '.', '.', '6', '.', '.'},
            {'.', '2', '.', '.', '.', '.', '.', '1', '.'},
            {'.', '.', '9', '.', '.', '.', '8', '.', '.'},
            {'.', '8', '.', '3', '.', '4', '.', '6', '.'},
            {'.', '.', '4', '.', '.', '.', '9', '.', '.'},
            {'5', '.', '.', '.', '.', '.', '.', '.', '7'}
    };

    SudokuSolver::solveNonomino(board, typeGrid);
    std::vector<int> colors = {4, 6, 0, 10, 3, 1, 13, 12, 8};
    setBald();
    // Print the result or indicate if it's invalid
    if (board.empty()) {
        printf("Invalid Nonomino Sudoku\n");
    } else {
        printf("Nonomino Sudoku Solution:\n  ");
        resetColor();
        for (unsigned char i = 0; i < 9; ++i) {
            for (unsigned char j = 0; j < 9; ++j) {
                // Output the number along with the type (color)
                setColor(colors[typeGrid[i][j]]);
                printf(" %c", board[i][j]);
            }
            printf(" ");
            resetColor();
            printf("\n  ");
        }
        printf("\n");
    }

    return 0;
}
