#include "Sudoku-Validator.h"
#include <iostream>

Puzzle::Puzzle(const std::vector<std::vector<int>>& initialGrid)
    : grid(initialGrid) {}

bool Puzzle::verifySolution() {
    if (grid.size() != 9) return false;
    for (const auto& row : grid) {
        if (row.size() != 9) return false;
        for (int v : row) {
            if (v < 1 || v > 9) return false;
        }
    }
    return true;
}

SudokuPuzzle::SudokuPuzzle(const std::vector<std::vector<int>>& initialGrid)
    : Puzzle(initialGrid) {}

bool SudokuPuzzle::verifySolution() {
    if (!Puzzle::verifySolution()) return false;

    //เช็คเเถว
    for (int r = 0; r < 9; ++r) {
        std::vector<bool> seen(10, false);
        for (int c = 0; c < 9; ++c) {
            int v = grid[r][c];
            if (seen[v]) return false;
            seen[v] = true;
        }
    }

    //เช็คคอลัมน์
    for (int c = 0; c < 9; ++c) {
        std::vector<bool> seen(10, false);
        for (int r = 0; r < 9; ++r) {
            int v = grid[r][c];
            if (seen[v]) return false;
            seen[v] = true;
        }
    }

    //เช็คบล็อกย่อย 3x3
    for (int br = 0; br < 3; ++br) {
        for (int bc = 0; bc < 3; ++bc) {
            std::vector<bool> seen(10, false);
            for (int r = br * 3; r < br * 3 + 3; ++r) {
                for (int c = bc * 3; c < bc * 3 + 3; ++c) {
                    int v = grid[r][c];
                    if (seen[v]) return false;
                    seen[v] = true;
                }
            }
        }
    }

    return true;
}

int main(){
    std::vector<std::vector<int>> valid1 = {
        {7, 9, 2, 1, 5, 4, 3, 8, 6},
        {6, 4, 3, 8, 2, 7, 1, 5, 9},
        {8, 5, 1, 3, 9, 6, 7, 2, 4},
        {2, 6, 5, 9, 7, 3, 8, 4, 1},
        {4, 8, 9, 5, 6, 1, 2, 7, 3},
        {3, 1, 7, 4, 8, 2, 9, 6, 5},
        {1, 3, 6, 7, 4, 8, 5, 9, 2},
        {9, 7, 4, 2, 3, 5, 6, 1, 8},
        {5, 2, 8, 6, 1, 9, 4, 3, 7}
    };
    SudokuPuzzle puzzle1(valid1);
    std::cout << (puzzle1.verifySolution()) << std::endl;

    std::vector<std::vector<int>> valid2 = {
        {7, 7, 2, 1, 5, 4, 3, 8, 6},  // มีเลข 7 ซ้ำกันในแถวนี้
        {6, 4, 3, 8, 2, 7, 1, 5, 9},
        {8, 5, 1, 3, 9, 6, 7, 2, 4},
        {2, 6, 5, 9, 7, 3, 8, 4, 1},
        {4, 8, 9, 5, 6, 1, 2, 7, 3},
        {3, 1, 7, 4, 8, 2, 9, 6, 5},
        {1, 3, 6, 7, 4, 8, 5, 9, 2},
        {9, 9, 4, 2, 3, 5, 6, 1, 8},  // มีเลข 9 ซ้ำกันในแถวนี้
        {5, 2, 8, 6, 1, 9, 4, 3, 7}
    };
    SudokuPuzzle puzzle2(valid2);
    std::cout << (puzzle2.verifySolution()) << std::endl;

    std::vector<std::vector<int>> valid3 = {
        {7, 0, 2, 1, 5, 4, 3, 8, 6},  // มีเลข 0
        {6, 4, 3, 8, 2, 7, 1, 5, 9},
        {8, 5, 1, 3, 9, 6, 7, 2, 4},
        {2, 6, 5, 9, 7, 3, 8, 4, 1},
        {4, 8, 9, 5, 6, 1, 2, 7, 3},
        {3, 1, 7, 4, 8, 2, 9, 6, 5},
        {1, 3, 6, 7, 4, 8, 5, 9, 2},
        {9, 7, 4, 2, 3, 5, 6, 1, 8},
        {5, 2, 8, 6, 1, 9, 4, 3, 7}
    };
    SudokuPuzzle puzzle3(valid3);
    std::cout << (puzzle3.verifySolution()) << std::endl;

    std::vector<std::vector<int>> valid4 = {
        {7, 9, 2, 1, 5, 4, 3, 8, 6},
        {6, 4, 3, 8, 2, 7, 1, 5, 9},
        {8, 5, 1, 3, 9, 6, 7, 2, 4},
        {2, 6, 5, 9, 7, 3, 8, 4, 1},
        {4, 8, 9, 5, 6, 1, 2, 7, 3},
        {3, 1, 7, 4, 8, 2, 9, 6, 5},
        {1, 3, 6, 7, 4, 8, 5, 9, 2},
        {9, 7, 4, 2, 3, 5, 6, 1, 8}
        // มีเเค่ 8 เเถวจึงไม่สมบูรณ์
    };
    SudokuPuzzle puzzle4(valid4);
    std::cout << (puzzle4.verifySolution()) << std::endl;

    std::vector<std::vector<int>> valid5 = {
        {7, 9, 2, 1, 5, 4, 3, 8, 6},
        {6, 4, 3, 8, 2, 7, 1, 5, 9},
        {8, 5, 1, 3, 9, 6, 7, 2, 4},
        {2, 6, 5, 9, 7, 3, 8, 4, 1},
        {4, 8, 9, 5, 6, 1, 2, 7},   // แถวนี้มีแค่ 8 ค่า
        {3, 1, 7, 4, 8, 2, 9, 6, 5},
        {1, 3, 6, 7, 4, 8, 5, 9, 2},
        {9, 7, 4, 2, 3, 5, 6, 1, 8}
    };
    SudokuPuzzle puzzle5(valid5);
    std::cout << (puzzle5.verifySolution()) << std::endl;
    return 0;
}