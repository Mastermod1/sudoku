#include "board.hpp"
#include <iostream>
#include <stdlib.h>

class Display
{
    public:
        Display(Board& board) : board(board) {}
        void printBoard()
        {
            system("clear");
            for(int i = 0; i < 81; i++)
                (i+1) % 9 == 0 ? std::cout << board.cellValue(i) << "\n" : std::cout << board.cellValue(i) << " ";
        }
    private:
        Board& board;
};