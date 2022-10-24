#include "../Headers/display.hpp"

void Display::printBoard()
{
    system("clear");
    std::cout << "   ";
    for(int i = 1; i <= 9; i++)
    {
        if(i % 3 == 0)
            std::cout << " " << i - 1 << "  ";
        else 
            std::cout << " " << i - 1 << " ";
    }
    std::cout << "\n";
    for(int i = 1; i <= 81; i++)
    {
        if((i - 1) % 27 == 0)
            printHorizontalLine(9 * 3 + 4);
        if((i - 1) % 9 == 0)
            std::cout  << i / 9 << " ";
        if((i - 1) % 3 == 0)
            std::cout << "|";
        std::cout << " " << board.getCell(i - 1) << " ";
        if(i % 9 == 0)
            std::cout << "|\n";
        
    }
    printHorizontalLine(9 * 3 + 4);
}

void Display::printHorizontalLine(int length)
{
    std::string s(length, '=');
    std::cout << "  " << s << "\n";            
}
