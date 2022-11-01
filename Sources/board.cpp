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

std::vector<std::pair<int,int>> Board::generatePosList()
{
    std::vector<std::pair<int,int>> list;
    for(int row = 0; row < 9; row++)
    {
        for(int col = 0; col < 9; col++)
        {
            list.push_back({row, col});
        }
    }
    return list;
}

std::vector<int> Board::generateSafeValueList(int row, int col)
{
    std::vector<int> list;
    for(int i = 1; i < 10; i++)
    {
        if(Validator(getBoard()).safeInsertOperation(row, col, i))
            list.push_back(i);
    }
    return list;
}

void Board::generateRandomBoard()
{   
    srand(time(0));
    board = {};
    auto posList = generatePosList();
    int i = 81;
    while(!posList.empty())
    {   
        int randomPosFromList = rand() % posList.size();
        auto randomIt = posList.begin() + randomPosFromList;

        int row = randomIt->first;
        int col = randomIt->second;

        auto safeValuesList = generateSafeValueList(row, col);

        int pos = rand() % safeValuesList.size();
        int randomValue = safeValuesList[pos];

        if(Validator(getBoard()).safeInsertOperation(row, col, randomValue))
        {
            setCell(row, col, randomValue);
            while(!isSolveable(getBoard(), 0, 0))
            {
                safeValuesList.erase(safeValuesList.begin() + pos);
                pos = rand() % safeValuesList.size();
                randomValue = safeValuesList[pos];
                setCell(row, col, randomValue);
            }
            posList.erase(randomIt);
        }
    }
}

