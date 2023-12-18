#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <array>

class SudokuSolver {
public:
    static bool isValidSudoku(std::vector<std::vector<char>>& board);

    static void solveSudoku(std::vector<std::vector<char>>& board);

    static void safeSolve(std::vector<std::vector<char>>& board);

private:
    static bool noDuplicate(const std::vector<std::vector<char>>& board);

    static bool noDupliRow(const std::vector<std::vector<char>>& board, unsigned char cur_row, unsigned char cur_col, char value);

    static bool noDupliRow(const std::vector<std::vector<char>>& board, unsigned char cur_row, unsigned char cur_col, char value, unsigned char begin, unsigned char end);

    static bool noDupliCol(const std::vector<std::vector<char>>& board, unsigned char cur_row, unsigned char cur_col, char value);

    static bool noDupliCol(const std::vector<std::vector<char>>& board, unsigned char cur_row, unsigned char cur_col, char value, unsigned char begin, unsigned char end);

    static bool noDupliMat(const std::vector<std::vector<char>>& board, unsigned char cur_row, unsigned char cur_col, char value);

    static bool canPlace(const std::vector<std::vector<char>>& board);

    static bool isValid(const std::vector<std::vector<char>>& board, std::pair<unsigned char, unsigned char> pos, unsigned char num);

    static bool solve(std::vector<std::vector<char>>& board, std::unordered_map<unsigned char, std::array<bool, 9>>& solver);
};

