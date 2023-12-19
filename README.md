# Sudoku Solver v1.2.0

Sudoku Solver v1.2.0 is an upgraded version of the Sudoku solver program written in C++. This release includes improvements for code quality and functionality.

## Changes in Version 1.2.0

- Introduced `static_cast` for several expressions to meet clangtidy standards.
- Added functions to solve nonomino sudoku puzzles, expanding beyond the original capability of solving classic sudoku.

## Changes in Version 1.1.1
- Improved efficiency by avoiding repetitive checking in the solving algorithm.

## Changes in Version 1.0.1

### Library Update

The library has been updated to version 1.0.1 and now includes the following files:

- `SudokuSolver.cpp`: Source file containing the implementation of the SudokuSolver class.
- `SudokuSolver.h`: Header file declaring the SudokuSolver class.
- `cmake-build-debug/`: Folder containing build artifacts, including the dynamic link library (`libSudokuServerLib.dll`) and its corresponding import library (`libSudokuServerLib.dll.a`).

Users can choose to use the library as either a static or shared library based on their preferences.

### Improved Performance

In an effort to enhance both time and space efficiency, all unnecessary `int` data types have been changed to `unsigned char`.

## Files

- `CMakeLists.txt`: CMake configuration file.
- `main.cpp`: Source code for the Sudoku Solver program.
- `SudokuSolver.cpp`: Source code containing the SudokuSolver class implementation.
- `SudokuSolver.h`: Header file declaring the SudokuSolver class.
- `cmake-build-debug/`: Folder containing build artifacts.

## Usage

In the `Test` folder, you'll find a `main.cpp` file demonstrating how to use the `SudokuSolver` class to solve both classic and nonomino sudoku puzzles. The `SudokuSolver` class provides five public functions:

1. **isValidSudoku:**
   ```cpp
   static bool isValidSudoku(const std::vector<std::vector<char>>& board);
   ```
   Use this function to determine if a given sudoku grid (`board`) is valid.

2. **isValidNonomino:**
   ```cpp
   static bool isValidNonomino(const std::vector<std::vector<char>>& board,
                                const std::vector<std::vector<unsigned char>>& typeGrid,
                                const std::vector<std::vector<std::pair<unsigned char, unsigned char>>>& typeSearch);
   ```
   This function checks the validity of a nonomino sudoku grid (`board`) and its corresponding `typeGrid`.

3. **solveSudoku:**
   ```cpp
   static void solveSudoku(std::vector<std::vector<char>>& board);
   ```
   Use this function to solve classic sudoku puzzles. Note that you must ensure the sudoku puzzle has a solution before calling this function.

4. **solveNonomino:**
   ```cpp
   static void solveNonomino(std::vector<std::vector<char>>& board,
                              const std::vector<std::vector<unsigned char>>& typeGrid);
   ```
   This safe function is designed for solving nonomino sudoku puzzles. It handles cases where no solution is found gracefully.

5. **safeSolve:**
   ```cpp
   static void safeSolve(std::vector<std::vector<char>>& board);
   ```
   `safeSolve` is optimized for solving classic sudoku puzzles. It is a safe function, meaning that if no solution is found, it will change the `board` to an empty state and return without causing errors.

These functions offer flexibility in solving different types of sudoku puzzles and provide checks for puzzle validity. Refer to the provided `main.cpp` file in the `Test` folder for practical examples of how to use these functions.

### Classic and Nonomino Sudoku Example

The `SudokuSolver` class provides functions to work with both classic and nonomino sudoku puzzles. Here's an example of how to use it for a classic and nonomino Sudoku:

```cpp
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

```

**This is the Classic Sudoku we used as example.**

![ClassicSudoku](https://github.com/JeongHan-Bae/SudokuSolver/assets/128088756/e34a19e7-54ae-42a7-adaf-fef8a230e631)

### Types in Nonomino Sudoku

In Nonomino Sudoku, each cell is associated with a "type", represented by a color. There are nine different types, each denoted by a unique color. The types are identified by the numbers 0 to 8 (inclusive).

For clarity, here's how the types are mapped to colors:

- Type 0: Color 1
- Type 1: Color 2
- Type 2: Color 3
- Type 3: Color 4
- Type 4: Color 5
- Type 5: Color 6
- Type 6: Color 7
- Type 7: Color 8
- Type 8: Color 9

**This is the Nonomino Sudoku we used as example.**

![NonominoSudoku](https://github.com/JeongHan-Bae/SudokuSolver/assets/128088756/b3739114-cabc-4376-aed8-afdd42739b79)

**These are results in the example.**

![ClassicSolu](https://github.com/JeongHan-Bae/SudokuSolver/assets/128088756/fb26aa4a-4751-4bab-8ee3-fcf73ce9e916)
![NonominoSolu](https://github.com/JeongHan-Bae/SudokuSolver/assets/128088756/32f19e4a-036c-4a1a-96d5-e7e285f20185)





### User Input and Validation Example

Here's an example demonstrating how to use the `SudokuSolver` class to validate and solve a Sudoku puzzle using user input:

```cpp
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

        // Use the SudokuSolver class to validate the Sudoku puzzle
        if (!SudokuSolver::isValidSudoku(sudokuGrid)) {
            printf("Invalid Sudoku puzzle.\n");
            continue;  // Ask the user to enter a valid Sudoku puzzle
        }

        // Use the SudokuSolver class to solve the Sudoku puzzle
        SudokuSolver::safeSolve(sudokuGrid);

        // Print the solved Sudoku grid or a message indicating failure
        printf("Solved Sudoku:\n");
        for (const auto& row : sudokuGrid) {
            for (char ch : row) {
                printf("%c ", ch);
            }
            printf("%c", '\n');
        }

        // Ask the user to continue or quit
        printf("Enter 'Quit' to quit (case-insensitive), \nOr line 0 to solve another Sudoku: \n");
    }

    return 0;
}
```

## License

This Sudoku solver is licensed under the [MIT License](LICENSE). Feel free to use, modify, and distribute the code as per the terms of the license. Users are encouraged to modify the program to suit their needs.
