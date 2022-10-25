#include "../Headers/game.hpp"

Game::Game()
{
    state = InProgress;
    std::array<std::array<int, 9>, 9> grid{
        {{3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}}
    };
    board = Board(grid);
}

void Game::checkGameState()
{
    if(board.isFilled())
        state = Won;
    // if(not isSolveable(board.getBoard(), 0, 0))
    //     state = Lost;
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

bool Game::isSolveable(std::array<std::array<int, 9>, 9> grid, int row, int col)
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
        if(Validator(board).safeInsertOperation(row, col, val))
        {
            grid[row][col] = val;
            if (isSolveable(grid, row, col + 1))
                return true;
        }
        grid[row][col] = 0;
    }
    return false;
}