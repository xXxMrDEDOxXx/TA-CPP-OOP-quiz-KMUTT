#pragma once
#include <vector>

class Puzzle {
protected:
    std::vector<std::vector<int>> grid;

public:
    // constructor: เก็บค่าเริ่มต้นของตารางลงในสมาชิก grid
    Puzzle(const std::vector<std::vector<int>>& initialGrid);
    virtual ~Puzzle() = default;

    // เมธอดตรวจสอบเบื้องต้น: ตรวจสอบขนาดตารางและช่วงของตัวเลข
    virtual bool verifySolution();
};

class SudokuPuzzle : public Puzzle {
public:
    // constructor: เรียกใช้ constructor ของ Puzzle เพื่อกำหนดค่าเริ่มต้น
    SudokuPuzzle(const std::vector<std::vector<int>>& initialGrid);

    bool verifySolution() override;
};