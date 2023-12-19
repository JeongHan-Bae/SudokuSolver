#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <array>

class SudokuSolver {
public:
    static bool isValidSudoku(const std::vector<std::vector<char>>& board);

    static bool isValidNonomino(const std::vector<std::vector<char>>& board,
                                const std::vector<std::vector<unsigned char>>& typeGrid,
                                const std::vector<std::vector<std::pair<unsigned char, unsigned char>>>& typeSearch);

    static void solveSudoku(std::vector<std::vector<char>>& board);

    static void solveNonomino(std::vector<std::vector<char>>& board,
                              const std::vector<std::vector<unsigned char>>& typeGrid);

    static void safeSolve(std::vector<std::vector<char>>& board);

private:
    static bool noDuplicate(const std::vector<std::vector<char>>& board);

    static bool noDuplicateNono(const std::vector<std::vector<char>>& board,
                                const std::vector<std::vector<unsigned char>>& typeGrid,
                                const std::vector<std::vector<std::pair<unsigned char, unsigned char>>>& typeSearch);

    static bool noDupliRow(const std::vector<std::vector<char>>& board, unsigned char cur_row, unsigned char cur_col, char value);

    static bool noDupliRow(const std::vector<std::vector<char>>& board, unsigned char cur_row, unsigned char cur_col, char value, unsigned char begin, unsigned char end);

    static bool noDupliCol(const std::vector<std::vector<char>>& board, unsigned char cur_row, unsigned char cur_col, char value);

    static bool noDupliCol(const std::vector<std::vector<char>>& board, unsigned char cur_row, unsigned char cur_col, char value, unsigned char begin, unsigned char end);

    static bool noDupliMat(const std::vector<std::vector<char>>& board, unsigned char cur_row, unsigned char cur_col, char value);

    static bool noDupliType(const std::vector<std::vector<char>>& board, unsigned char cur_row, unsigned char cur_col,
                            const std::vector<std::vector<unsigned char>>& typeGrid,
                            const std::vector<std::vector<std::pair<unsigned char, unsigned char>>>& typeSearch,
                            char value);

    static bool canPlace(const std::vector<std::vector<char>>& board);

    static bool canPlaceNono(const std::vector<std::vector<char>>& board,
                             const std::vector<std::vector<unsigned char>>& typeGrid,
                             const std::vector<std::vector<std::pair<unsigned char, unsigned char>>>& typeSearch);

    static bool isValid(const std::vector<std::vector<char>>& board, std::pair<unsigned char, unsigned char> pos, unsigned char num);

    static bool isValidNono(const std::vector<std::vector<char>>& board, std::pair<unsigned char, unsigned char> pos,
                            const std::vector<std::vector<unsigned char>>& typeGrid,
                            const std::vector<std::vector<std::pair<unsigned char, unsigned char>>>& typeSearch,
                            unsigned char num);

    static bool solve(std::vector<std::vector<char>>& board, std::unordered_map<unsigned char, std::array<bool, 9>>& solver);

    static bool solveNono(std::vector<std::vector<char>>& board, std::unordered_map<unsigned char, std::array<bool, 9>>& solver,
                          const std::vector<std::vector<unsigned char>>& typeGrid,
                          const std::vector<std::vector<std::pair<unsigned char, unsigned char>>>& typeSearch);
};

