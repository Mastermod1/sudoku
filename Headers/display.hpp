#pragma once
#include <iostream>
#include <string>

class Display
{
    public:
        Display(Board& board) : board(board) {}
        void printBoard();
        
    private:
        void printHorizontalLine(int length);
        
        Board& board;
};