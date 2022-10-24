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
        Board(std::array<int, 81> givenBoard) {board = givenBoard;}
        int getCell(int pos) {return board[pos];}
        void setCell(int pos, int val);
        std::array<int, 81> getBoard() {return board;}
    private:
        std::array<int, 81> board;
};