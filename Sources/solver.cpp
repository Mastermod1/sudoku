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
