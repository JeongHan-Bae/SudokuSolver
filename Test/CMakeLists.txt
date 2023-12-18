cmake_minimum_required(VERSION 3.24)
project(Test)

set(CMAKE_CXX_STANDARD 17)

# Set the path to the SudokuServer library
set(SUDOKU_SOLVER_DIR "${CMAKE_SOURCE_DIR}/..")
set(SUDOKU_SOLVER_LIB_DIR "${SUDOKU_SOLVER_DIR}/cmake-build-debug")

add_executable(Test main.cpp)

# Include the directory containing SudokuSolver.h
target_include_directories(Test PRIVATE "${SUDOKU_SOLVER_DIR}")
# Link against the SudokuServer library
target_link_libraries(Test PRIVATE "${SUDOKU_SOLVER_LIB_DIR}/libSudokuServerLib.dll")

# Set the working directory for the Test executable
set_target_properties(Test PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/Test")
