#include "../Headers/validator.hpp"

bool Validator::valueNotInSquare(int row, int col, int value)
{
    int squaredCol = col / 3;
    int squaredRow = row / 3;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board.getCell(squaredRow + i, squaredCol + j) == value)
                return false;
        }
    }
    return true;
}

bool Validator::valueNotInRow(int row, int value)
{   
    for(int i = 0; i < 9; i++)
    {
        if(board.getCell(row, i) == value)
            return false;
    }
    return true;
}

bool Validator::valueNotInCol(int col, int value)
{
    for(int i = 0; i < 9; i++)
    {
        if(board.getCell(i, col) == value)
            return false;
    }
    return true;
}

bool Validator::safeInsertOperation(int row, int col, int value)
{
    return valueNotInRow(row, value) && valueNotInCol(col, value) && valueNotInSquare(row, col, value);
}