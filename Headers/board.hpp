#pragma once

#include <array>
#include "../Sources/board.cpp"
#include <initializer_list>

class Board
{
    public:
        Board()
        {
            board.fill(0);
        }
        Board(std::array<int, 81> brd) {board = brd;};
        int cellValue(int pos) { return board[pos];}
        void setCell(int pos, int val) {if(val > 9 or val < 0) return; board[pos] = val;}
        bool isFilled()
        {
            for(auto it : board)
                if(it == 0)
                    return false;
            return true;
        }
        std::array<int, 81> getBoard() {return board;}

    private:
        std::array<int, 81> board;
};