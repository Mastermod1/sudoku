#pragma once
#include <array>
#include <time.h>
#include <cstdlib>
#include <vector>
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
        bool isSolveable(std::array<std::array<int, 9>, 9> grid, int row, int col);
        std::array<std::array<int, 9>, 9> getBoard() {return board;}
    private:
        std::array<std::array<int, 9>, 9> board;
        void generateRandomBoard();
};