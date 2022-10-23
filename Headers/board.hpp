#pragma once
#include <array>
#include <initializer_list>
#include <algorithm>


int tabToPos(int row, int col)
{
    return row * 9 + col;
}
class Board
{
    public:
        Board() {board.fill(0);}
        Board(std::array<int, 81> brd) {board = brd;};
        int getCell(int pos) { return board[pos];}
        void setCell(int pos, int val);
    private:
        std::array<int, 81> board;
};