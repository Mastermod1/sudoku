#include "../Headers/board.hpp"

void Board::setCell(int row, int col, int val)
{
    board[row][col] = val;
}

bool Board::isFilled()
{
    for(int row = 0; row < 9; row++)
        if(std::find(board[row].begin(), board[row].end(), 0) != board[row].end())
            return false;
    return true;
}
