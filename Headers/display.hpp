#pragma once
#include <iostream>
#include <string>

class Display
{
    public:
        Display(){}
        void printBoard(Board& board);
        void printMenu();
    private:
        void printHorizontalLine(int length);
};