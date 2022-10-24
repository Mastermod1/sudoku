#include "../Headers/board.hpp"

void Board::setCell(int pos, int val)
{
    if(val > 9 or val < 0) 
        return; 
    board[pos] = val;
}

bool Board::isFilled()
{
    return std::find(board.begin(), board.end(), 0) == board.end();
}
