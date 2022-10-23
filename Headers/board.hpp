#pragma once

#include <array>
#include "../Sources/board.cpp"

class Board
{
    public:
        Board()
        {
            board.fill(0);
        }
        int cellValue(int pos) { return board[pos];}
        void setCell(int pos, int val) {if(val > 9 or val < 0) return; board[pos] = val;}


    private:
        std::array<int, 81> board;
};