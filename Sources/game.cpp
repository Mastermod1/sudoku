#include "../Headers/game.hpp"

Game::Game()
{
    state = InProgress;
    board = Board({
        0,0,0,3,0,0,0,0,0,
        3,0,9,7,2,6,0,0,8,
        2,0,6,8,0,0,3,0,4,
        0,3,2,0,7,0,5,0,0,
        0,0,8,1,6,0,0,3,0,
        7,0,0,0,3,8,0,0,0,
        0,0,0,0,0,0,0,0,5,
        9,1,0,0,0,0,0,0,3,
        0,0,0,2,0,4,0,0,1
    });
}

void Game::checkGameState()
{
    if(board.isFilled())
        state = Won;
    if(not isSolveable(board.getBoard(), 0, 0))
        state = Lost;
}

void Game::startGameLoop()
{
    Display display(board);
    Input input(board);
    std::array<std::string, 2> endMsg = {"GG EZ! You won!\n","LOL, so bad loser!\n"};
    int row, col, val;
    while(state == InProgress)
    {
        display.printBoard();
        std::cout << "Value: Row: Col:\n";
        std::cin >> val >> row >> col;
        input.handleInput(row, col, val);
        checkGameState();
    }
    std::cout << endMsg[state];
}

bool Game::isSolveable(std::array<int, 81> grid, int row, int col)
{
    if(row == 8 and col == 9)
        return true;

    if(col == 9)
    {
        row++;
        col = 0;
    }

    int pos = tabToPos(row, col);

    if(grid[pos] > 0)
        return isSolveable(grid, row, col + 1);

    for(int val = 1; val < 10; val++)
    {
        if(Validator(board).safeInsertOperation(row, col, val))
        {
            grid[pos] = val;
            if (isSolveable(grid, row, col + 1))
                return true;
        }
        grid[pos] = 0;
    }
    return false;
}