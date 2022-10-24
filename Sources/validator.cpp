#include "../Headers/validator.hpp"

bool Validator::valueNotInSquare(int row, int col, int value)
{
    int squaredCol = col / 3;
    int squaredRow = row / 3;

    int startPos = 3 * squaredCol + 27 * squaredRow;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board.getCell(startPos + i + j*9) == value)
                return false;
        }
    }
    return true;
}

bool Validator::valueNotInRow(int row, int value)
{
    for(int i = row*9; i < (row+1) * 9; i++)
    {
        if(board.getCell(i) == value)
            return false;
    }
    return true;
}

bool Validator::valueNotInCol(int col, int value)
{
    for(int i = col; i < 81; i+=9)
    {
        if(board.getCell(i) == value)
            return false;
    }
    return true;
}

bool Validator::safeInsertOperation(int row, int col, int value)
{
    return valueNotInRow(row, value) && valueNotInCol(col, value) && valueNotInSquare(row, col, value);
}