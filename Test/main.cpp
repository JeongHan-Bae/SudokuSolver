#include <iostream>
#include "SudokuSolver.h"

int main() {

    printf("Welcome to Sudoku Solver!\n");

    printf("Please enter the line %d: \n", 0);


    while (true) {
        std::vector<std::vector<char>> sudokuGrid =  {
                {'.','.','.','.','.','.','.','.','.'},
                {'.','.','.','.','.','.','.','.','.'},
                {'.','.','.','.','.','.','.','.','.'},
                {'.','.','.','.','.','.','.','.','.'},
                {'.','.','.','.','.','.','.','.','.'},
                {'.','.','.','.','.','.','.','.','.'},
                {'.','.','.','.','.','.','.','.','.'},
                {'.','.','.','.','.','.','.','.','.'},
                {'.','.','.','.','.','.','.','.','.'}
        };

        for (int i = 0; i < 9; ++i) {
            if(i)printf("Please enter the line %d: \n", i);
            std::string line;
            std::getline(std::cin, line);
            if(!i){
                std::string userChoice = line;
                std::transform(userChoice.begin(), userChoice.end(), userChoice.begin(), ::tolower);

                if (userChoice == "quit") {
                    return 0;  // Terminate the program
                }
            }
            for (int j = 0, k = 0; j < 9 && k < line.size(); ++j) {
                // Skip over spaces
                while (k < line.size() && line[k] == ' ') {
                    ++k;
                }

                // Fill in the sudokuGrid
                if (k < line.size()) {
                    sudokuGrid[i][j] = line[k];
                    ++k;
                }
            }
        }

        // Use the SudokuSolver class to solve the Sudoku puzzle
        SudokuSolver::safeSolve(sudokuGrid);

        // Check if the Sudoku puzzle is invalid
        if (sudokuGrid.empty()) {
            printf("Invalid Sudoku puzzle.\n");
        } else {
            // Print the solved Sudoku grid or a message indicating failure
            printf("Solved Sudoku:\n");
            for (const auto& row : sudokuGrid) {
                for (char ch : row) {
                    printf("%c ", ch);
                }
                printf("%c", '\n');
            }
        }

        // Ask the user to continue or quit
        printf("Enter 'Quit' to quit (case-insensitive), \nOr line 0 to solve another Sudoku: \n");
    }

}
