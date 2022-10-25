#pragma once
#include <array>
#include <initializer_list>
#include <algorithm>

class Board
{
    public:
        Board() {board = {};}
        Board(std::array<std::array<int, 9>, 9> givenBoard) {board = givenBoard;}
        int getCell(int row, int col) {return board[row][col];}
        void setCell(int row, int col, int val);
        bool isFilled();
        std::array<std::array<int, 9>, 9> getBoard() {return board;}
    private:
        std::array<std::array<int, 9>, 9> board;
};