# <span style="font-size: larger;">數獨求解者</span> (<span style="font-size: smaller;">수독 구해자</span>) Version1.2.0

<span style="font-size: larger;">數獨求解者</span>(수독 구해자 version 1.2.0)는 C++로 作成(작성)된 數獨(수독) 求解(구해) 項目(항목)의 進階(진계)된 Version 입니다. 이 Release 에는 Code 品質(품질) 및 機能(기능) 向上(향상)이 包含(포함)되어 있습니다.

<span style="font-size: larger;">모든 細部(세부) 事項(사항)은 英語(영어)로 Code 를 더 잘 理解(리해)하기 爲(위)해  作成(작성)되어 있습니다.</span>

For the English version, visit [here](README.md).

## Version 1.2.0 의 <span style="font-size: larger;">革新</span>(<span style="font-size: smaller;">혁신</span>)

- clangTidy 標準(표준)을 充足(충족)하기 爲(위)해 여러 表現(표현)에 static_cast 를 導入(도입)했습니다.
- 奇異數獨(기이 수독, en: Nonomino Sudoku)을 解決(해결)하는 機能(기능)을 追加(추가)하여, 經典數獨(경전 수독, en: Classic Sudoku)을 解決(해결)하는 原來(원래) 能力(능력)을 넘어 擴張(확장)했습니다.

## Version 1.1.1 의 <span style="font-size: larger;">革新</span>(<span style="font-size: smaller;">혁신</span>)

- 解決(해결) 算法(산법, en: Algorithm)에서 反復(반복)적인 確認(확인)을 피함으로써 效率(효률)성을 向上(향상)시켰습니다.

## Version 1.0.1 의 <span style="font-size: larger;">革新</span>(<span style="font-size: smaller;">혁신</span>)


### Library <span style="font-size: larger;">革新</span>(<span style="font-size: smaller;">혁신</span>)

Library 가 Version 1.0.1로 更新(경신)되었으며 이제 다음 文件(문건, en: Files)이 包含(포함)되어 있습니다:

- `SudokuSolver.cpp`: Source file containing the implementation of the SudokuSolver class.
- `SudokuSolver.h`: Header file declaring the SudokuSolver class.
- `cmake-build-debug/`: Folder containing build artifacts, including the dynamic link library (`libSudokuServerLib.dll`) and its corresponding import library (`libSudokuServerLib.dll.a`).

使用者(사용자)들은 選好(선호)에 따라 library 를 靜(정, en: static)적 또는 公有(공유, en: shared) library 로 使用(사용)할 수 있습니다.

### <span style="font-size: larger;">性能向上</span>(<span style="font-size: smaller;">성능 향상</span>)

時間(시간) 및 空間(공간) 效率(효를)성을 向上(향상)시키기 爲(위)해 모든 不必要(불필요)한 `int` 數據(수거) 型式(형식)이 `unsigned char`로 變更(변경)되었습니다.

## <span style="font-size: larger;">文件</span>(<span style="font-size: smaller;">문건, Files</span>)

- `CMakeLists.txt`: CMake configuration file.
- `main.cpp`: Source code for the Sudoku Solver program.
- `SudokuSolver.cpp`: Source code containing the SudokuSolver class implementation.
- `SudokuSolver.h`: Header file declaring the SudokuSolver class.
- `cmake-build-debug/`: Folder containing build artifacts.

## <span style="font-size: larger;">使用</span>(<span style="font-size: smaller;">사용, Usage</span>)

`Test` Folder 에서는 `main.cpp` 脚本(각본, en: script)이 있습니다. 이 文件(문건, en: Files)은 `SudokuSolver` 類(류, en: class)를 使用(사용)하여 經典(경전, en: Classic) 및 奇異數獨(기이수독, en: Nonomino Sudoku) 解決해결하는 方法방법을 보여줍니다. `SudokuSolver` 類(류, en: class)는 다섯 가지 公開(공개, en: public) 函數(함수, en: function)를 提供(제공)합니다:

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

![ClassicSolu](https://github.com/JeongHan-Bae/SudokuSolver/assets/128088756/6e2d646e-83f4-46b4-9cb6-48154aeeb6e9)
![NonominoSolu](https://github.com/JeongHan-Bae/SudokuSolver/assets/128088756/d6d4398b-211a-4e50-ba82-9d848fdf83ca)


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
