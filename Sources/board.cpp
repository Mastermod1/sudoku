#include "../Headers/board.hpp"
#include "../Sources/validator.cpp"


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

bool Board::isSolveable(std::array<std::array<int, 9>, 9> grid, int row, int col)
{
    if(row == 8 and col == 9)
        return true;

    if(col == 9)
    {
        row++;
        col = 0;
    }

    if(grid[row][col] > 0)
        return isSolveable(grid, row, col + 1);

    for(int val = 1; val < 10; val++)
    {   
        if(Validator(grid).safeInsertOperation(row, col, val))
        {
            grid[row][col] = val;
            if (isSolveable(grid, row, col + 1))
                return true;
        }
        grid[row][col] = 0;
    }
    return false;
}

void Board::generateRandomBoard()
{   
    srand(time(0));

    std::vector<int> validValues;

    while(!isFilled())
    {
        int row = rand() % 10;
        int col = rand() % 10;

        if(getCell(row, col) > 0)
            continue;
        
        for(int i = 1; i < 10; i++)
        {
            if(Validator(getBoard()).safeInsertOperation(row, col, i))
                validValues.push_back(i);
        }
        if(isSolveable(getBoard(), 0, 0))
            setCell(row, col, validValues[rand() % validValues.size()]);
    }

    


}