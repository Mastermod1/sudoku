#pragma once
#include <array>
#include "../Sources/board.cpp"

class Solver
{
    public:
        Solver(Board& board) : board(board) {};

        bool solve(int, int);

    private:
        bool safeInsertOperation(int row, int col, int value);
        bool valueNotInSquare(int row, int col, int value);
        bool valueNotInRow(int row, int value);
        bool valueNotInCol(int col, int value);
        Board& board;    
};