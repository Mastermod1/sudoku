#include "../Headers/solver.hpp"


bool Solver::solve(int row = 0, int col = 0)
{
    if(row == 8 and col == 9)
        return true;

    if(col == 9)
    {
        row++;
        col = 0;
    }

    int pos = tabToPos(row, col);

    if(board.getCell(pos) > 0)
        return solve(row, col + 1);

    for(int val = 1; val < 10; val++)
    {
        if(safeInsertOperation(row, col, val))
        {
            board.setCell(pos, val);
            if (solve( row, col + 1))
                return true;
        }
        board.setCell(pos, 0);
    }
    return false;
}

bool Solver::safeInsertOperation(int row, int col, int value)
{
    return valueNotInRow(row, value) && valueNotInCol(col, value) && valueNotInSquare(row, col, value);
}

bool Solver::valueNotInSquare(int row, int col, int value)
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

bool Solver::valueNotInRow(int row, int value)
{
    for(int i = row*9; i < (row+1) * 9; i++)
    {
        if(board.getCell(i) == value)
            return false;
    }
    return true;
}

bool Solver::valueNotInCol(int col, int value)
{
    for(int i = col; i < 81; i+=9)
    {
        if(board.getCell(i) == value)
            return false;
    }
    return true;
}

