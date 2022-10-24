#include "../Headers/game.hpp"

Game::Game()
{
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

void Game::startGameLoop()
{
    Display display(board);
    int row, col, val;
    while(true)
    {
        display.printBoard();
        std::cout << "Value: Row: Col:\n";
        std::cin >> val >> row >> col;
        //input.handleInput();
        board.setCell(tabToPos(row, col), val);
    }
}