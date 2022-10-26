#pragma once
#include <iostream>
#include <string>

class Display
{
    public:
        Display(Board& board) : board(board) {}
        void printBoard();
        
    private:
        Board& board;
        void printHorizontalLine(int length);
};