#pragma once
#include "board.hpp"
#include <array>
#include <iostream>

class Solver
{
    public:
        Solver(Board& board) : board(board) {};

        bool solve(int row = 0, int col = 0)
        {
            std::cout << "row " << row << " col " << col << "\n";
            if(row == 8 and col == 9)
                return true;

            if(col == 9)
            {
                row++;
                col = 0;
            }

            int pos = row*9 + col;
            std::cout << pos << "\n";

            if(board.cellValue(pos) > 0)
                return solve(row, col + 1);

            for(int val = 1; val < 10; val++)
            {
                if(valueNotInRow(row, val))
                {
                    if(valueNotInCol(col, val))
                    {
                        if(valueNotInSquare(row, col, val))
                        {
                            board.setCell(pos, val);
                            if (solve( row, col + 1))
                                return true;
                        }
                    }
                }
                board.setCell(pos, 0);
            }
            return false;
        }

    private:
        bool valueNotInSquare(int row, int col, int value)
        {
            int squaredCol = col / 3;
            int squaredRow = row / 3;

            int startPos = 3 * squaredCol + 27 * squaredRow;
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    if(board.cellValue(startPos + i + j*9) == value)
                        return false;
                }
            }
            return true;
    
        }
        bool valueNotInRow(int row, int value)
        {
            for(int i = row*9; i < (row+1) * 9; i++)
            {
                if(brd[i] == value)
                    return false;
            }
            return true;
        }
        bool valueNotInCol(int col, int value)
        {
            for(int i = col; i < 81; i+=9)
            {
                if(brd[i] == value)
                    return false;
            }
            return true;
        }
        std::array<int, 81> brd;
        Board& board;
    
};