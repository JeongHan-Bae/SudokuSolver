#include "SudokuSolver.h"

bool SudokuSolver::isValidSudoku(std::vector<std::vector<char>>& board) {
    return noDuplicate(board) && canPlace(board);
}

void SudokuSolver::solveSudoku(std::vector<std::vector<char>>& board) {
    // Initialize the data structure to track possibilities for each empty cell
    std::unordered_map<unsigned char, std::array<bool, 9>> solver;

    // Populate possibilities map for empty cells
    for (unsigned char i = 0; i < 9; ++i) {
        for (unsigned char j = 0; j < 9; ++j) {
            if (board[i][j] < '1' || board[i][j] > '9') {
                solver[9 * i + j] = { true, true, true, true, true, true, true, true, true }; // Initialize with default values
            }
        }
    }

    // Call the recursive solve function to solve the Sudoku puzzle
    // If Invalid, return {};
    if (!solve(board, solver)) board = {};
}

void SudokuSolver::safeSolve(std::vector<std::vector<char>>& board){
    // Test is the Sudoku Grid is a valid Grid to solve
    if (!isValidSudoku(board)){
        board = {};
        return;
    }
    // Solve the Sudoku
    solveSudoku(board);
}

bool SudokuSolver::noDuplicate(const std::vector<std::vector<char>>& board) {
    // Check for each existing number if it has duplicate
    for(unsigned char i = 0; i < 9; ++i){
        for(unsigned char j = 0; j < 9; ++j){
            if(board[i][j] >= '1' && board[i][j] <= '9' ){
                if(!noDupliRow(board, i, j, board[i][j], i, 9)) return false;
                if(!noDupliCol(board, i, j, board[i][j], j, 9)) return false;
                if(!noDupliMat(board, i, j, board[i][j])) return false;
            }
        }
    }
    return true;
}

bool SudokuSolver::noDupliRow(const std::vector<std::vector<char>>& board, unsigned char cur_row, unsigned char cur_col, char value){
    // Check Row begin with 0, end with 9
    return noDupliRow(board, cur_row, cur_col, value, 0, 9);
}

bool SudokuSolver::noDupliRow(const std::vector<std::vector<char>>& board, unsigned char cur_row, unsigned char cur_col, char value, unsigned char begin, unsigned char end){
    // Check row
    for(unsigned char i = begin; i < end; ++i){
        if(board[i][cur_col] == value && i != cur_row){
            return false;
        }
    }
    return true;
}

bool SudokuSolver::noDupliCol(const std::vector<std::vector<char>>& board, unsigned char cur_row, unsigned char cur_col, char value){
    // Check Column begin with 0, end with 9
    return noDupliCol(board, cur_row, cur_col, value, 0, 9);
}

bool SudokuSolver::noDupliCol(const std::vector<std::vector<char>>& board, unsigned char cur_row, unsigned char cur_col, char value, unsigned char begin, unsigned char end){
    // Check Column
    for(unsigned char j = begin; j < end; ++j){
        if(board[cur_row][j] == value && j != cur_col){
            return false;
        }
    }
    return true;
}

bool SudokuSolver::noDupliMat(const std::vector<std::vector<char>>& board, unsigned char cur_row, unsigned char cur_col, char value){
    // Check 3x3 Matrix
    for(unsigned char k = 0; k < 9; ++k){
        unsigned char x = 3 * (unsigned char)(cur_row / 3) + (unsigned char)(k / 3);
        unsigned char y = 3 * (unsigned char)(cur_col / 3) + (k % 3);
        if(board[x][y] == value && x != cur_row && y != cur_col){
            return false;
        }
    }
    return true;
}

bool SudokuSolver::canPlace(const std::vector<std::vector<char>>& board) {

    // Check Column
    for (unsigned char col = 0; col < 9; ++col) {
        std::vector<bool> exist(9, false);
        std::vector<bool> places(9, false);
        for (unsigned char i = 0; i < 9; ++i) {
            if (board[i][col] >= '1' && board[i][col] <= '9') {
                exist[board[i][col] - '1'] = true;
            } else {
                places[i] = true;
            }
        }
        for (unsigned char num = 0; num < 9; ++num) {
            if (!exist[num]) {
                bool valid = false;
                for(unsigned char i = 0; i < 9; ++i){
                    if(places[i]){
                        // Avoid checking the same Col or the checked vals
                        if(noDupliRow(board, i, col, num + '1', i, 9)
                           && noDupliMat(board, i, col, num + '1')){
                            valid = true;
                            break;
                        }
                    }
                }
                if (!valid) return false;
            }
        }
    }
    // Check Row
    for (unsigned char row  = 0; row < 9; ++row) {
        std::vector<bool> exist(9, false);
        std::vector<bool> places(9, false);
        for (unsigned char j = 0; j < 9; ++j) {
            if (board[row][j] >= '1' && board[row][j] <= '9') {
                exist[board[row][j] - '1'] = true;
            } else {
                places[j] = true;
            }
        }
        for (unsigned char num = 0; num < 9; ++num) {
            if (!exist[num]) {
                bool valid = false;
                for(unsigned char j = 0; j < 9; ++j){
                    if(places[j]) {
                        // Avoid checking the same Row or the checked vals
                        if (noDupliCol(board, row, j, num + '1', j, 9)
                            && noDupliMat(board, row, j, num + '1')){
                            valid = true;
                            break;
                        }
                    }
                }
                if (!valid) return false;
            }
        }
    }
    // Check 3x3 Matrix
    for (unsigned char square = 0; square < 9; ++square) {
        std::vector<bool> exist(9, false);
        std::vector<bool> places(9, false);
        for (unsigned char k = 0; k < 9; ++k) {
            unsigned char x = 3 * (unsigned char)(square/3) + (unsigned char)(k/3);
            unsigned char y = 3 * (square % 3) + k % 3;
            if (board[x][y] >= '1' && board[x][y] <= '9') {
                exist[board[x][y] - '1'] = true;
            } else {
                places[k] = true;
            }
        }
        for (unsigned char num = 0; num < 9; ++num) {
            if (!exist[num]) {
                bool valid = false;
                for(unsigned char k = 0; k < 9; ++k){
                    if(places[k]) {
                        unsigned char x = 3 * (unsigned char)(square/3) + (unsigned char)(k/3);
                        unsigned char y = 3 * (square % 3) + k % 3;
                        // Avoid checking the same Mat
                        if (noDupliRow(board, x, y, num + '1')
                            && noDupliCol(board, x, y, num + '1')){
                            valid = true;
                            break;
                        }
                    }
                }
                if (!valid) return false;
            }
        }
    }
    return true;
}

bool SudokuSolver::isValid(const std::vector<std::vector<char>>& board, std::pair<unsigned char, unsigned char> pos, unsigned char num) {
    // Implement the validity check for rows, columns, and small squares
    return noDupliRow(board, pos.first, pos.second, num + '1')
           && noDupliCol(board, pos.first, pos.second, num + '1')
           && noDupliMat(board, pos.first, pos.second, num + '1');
}

bool SudokuSolver::solve(std::vector<std::vector<char>>& board, std::unordered_map<unsigned char, std::array<bool, 9>>& solver) {
    bool continue_solve = true;
    unsigned char target = (*solver.begin()).first;
    unsigned char chances = 9;
    while (continue_solve) {
        continue_solve = false;

        for (auto& item : solver) {
            unsigned char i = item.first / 9;
            unsigned char j = item.first % 9;

            std::array<bool, 9>& possibilities = item.second;
            unsigned char sum = 0;
            unsigned char last_valid_num = 0;

            for (unsigned char k = 0; k < 9; ++k) {
                if (possibilities[k]) {
                    possibilities[k] = isValid(board, { i, j }, k);
                    sum += possibilities[k];
                    if (possibilities[k]) {
                        last_valid_num = k;
                    }
                }
            }

            if (sum == 0) {
                return false; // No valid possibilities for this cell
            }
            else if (sum == 1) {
                // Set the only valid value in the cell
                board[i][j] = last_valid_num + '1';
                solver.erase(item.first);
                continue_solve = true;
            }
            //get the cell with fewer possibilities
            if (sum < chances) {
                target = item.first;
            }
        }
    }

    if (solver.empty()) {
        return true; // Board is solved
    }

    unsigned char i = target / 9;
    unsigned char j = target % 9;

    for (unsigned char k = 0; k < 9; ++k) {
        if (solver[target][k]) {
            // Try setting the cell to the valid value and recursively solve
            std::vector<std::vector<char>> new_board = board;
            std::unordered_map<unsigned char, std::array<bool, 9>> new_solver = solver;
            new_solver.erase(i * 9 + j);
            new_board[i][j] = k + '1';

            if (solve(new_board, new_solver)) {
                board = new_board;
                return true;
            }
        }
    }

    return false;
}