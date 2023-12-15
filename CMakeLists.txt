cmake_minimum_required(VERSION 3.24)
project(SudokuServerLib)

# Add your source files
set(SOURCE_FILES SudokuSolver.cpp)

# Create a dynamic library from the source files
add_library(SudokuServerLib SHARED ${SOURCE_FILES})
