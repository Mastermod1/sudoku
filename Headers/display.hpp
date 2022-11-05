#pragma once
#include <iostream>
#include <string>

class Display
{
    public:
        Display(){}
        void printBoard(Board& board);
        
    private:
        void printHorizontalLine(int length);
};