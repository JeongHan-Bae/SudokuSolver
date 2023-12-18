# Sudoku Solver v1.1.1

Sudoku Solver v1.1.1 is an enhanced version of the Sudoku solver program written in C++. This update introduces a new library structure, performance improvements, and additional features.

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

## Building

To build the Sudoku solver, ensure you have CMake installed. Navigate to the Test project root directory and run the following commands:

```bash
mkdir build
cd build
cmake ..
make
```

This will generate the executable `Test.exe` in the `Test/cmake-build-debug` folder.

## Usage

Run the program by executing the `SudokuSolver.exe` file. Enter Sudoku puzzles line by line, with empty cells represented by '.' or '0'. The program will solve the puzzle and display the result. You can enter 'quit' at any time to exit the program.

The program automatically ignores spaces.

### Example Sudoku Puzzle:

```cmd
5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9
```

### Example Output (Valid Sudoku):

```cmd
Welcome to Sudoku Solver!
Please enter the line 0:
5 3 . . 7 . . . .
Please enter the line 1:
6 . . 1 9 5 . . .
Please enter the line 2:
. 9 8 . . . . 6 .
Please enter the line 3:
8 . . . 6 . . . 3
Please enter the line 4:
4 . . 8 . 3 . . 1
Please enter the line 5:
7 . . . 2 . . . 6
Please enter the line 6:
. 6 . . . . 2 8 .
Please enter the line 7:
. . . 4 1 9 . . 5
Please enter the line 8:
. . . . 8 . . 7 9
Solved Sudoku:
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
Enter 'Quit' to quit (case-insensitive),
Or line 0 to solve another Sudoku:
quit
```

### Example Output (Invalid Sudoku):

```cmd
Welcome to Sudoku Solver!
Please enter the line 0:
5 3 . . 7 . . . .
Please enter the line 1:
6 . . 1 9 5 . . .
Please enter the line 2:
. 9 8 . . . . 6 .
Please enter the line 3:
8 . . . 6 . . . 3
Please enter the line 4:
4 . . 8 . 3 . . 1
Please enter the line 5:
7 . . . 2 . . . 6
Please enter the line 6:
. 6 . . . . 2 8 .
Please enter the line 7:
. . . 4 1 9 . . 5
Please enter the line 8:
. . . 4 1 9 . . 5
Invalid Sudoku puzzle.
Enter 'Quit' to quit (case-insensitive),
Or line 0 to solve another Sudoku:
```

## License

This Sudoku solver is licensed under the [MIT License](LICENSE). Feel free to use, modify, and distribute the code as per the terms of the license. Users are encouraged to modify the program to suit their needs.
