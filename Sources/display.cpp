#include "../Headers/display.hpp"

void Display::printBoard(Board& board)
{
    system(CLR);
    std::cout << "   ";
    for(int i = 1; i <= 9; i++)
    {
        if(i % 3 == 0)
            std::cout << " " << i - 1 << "  ";
        else 
            std::cout << " " << i - 1 << " ";
    }
    std::cout << "\n";
    for(int row = 0; row < 9; row++)
    {
        if(row % 3 == 0)
            printHorizontalLine(9 * 3 + 4);
        std::cout << row << " |";
        for(int col = 0; col < 9; col++)
        {
            std::string str = (col+1) % 3 == 0 ? " |" : " ";
            std::cout << " " << board.getCell(row, col) << str;
        }
        std::cout << "\n";
    }
    printHorizontalLine(9 * 3 + 4);
}

void Display::printMenu()
{
    std::cout << "===Sudoku===\n";
    std::cout << " 1. Start\n 2. Exit\n";
}

void Display::printHorizontalLine(int length)
{
    std::string s(length, '=');
    std::cout << "  " << s << "\n";            
}
