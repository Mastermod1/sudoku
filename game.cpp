#include <iostream>
#include "Headers/display.hpp"

int main()
{
    Board board;
    Display display(board);
    for(int i = 0; i < 5; i++)
    {
        display.printBoard();
        board.setCell(i*2, 9);
    }
}