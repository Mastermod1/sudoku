#include "../Headers/game.hpp"

Game::Game()
{
    state = InProgress;
    board = Board();
}

void Game::checkGameState()
{
    if(board.isFilled())
        state = Won;
    if(not board.isSolveable(board.getBoard(), 0 ,0))
        state = Lost;
}

void Game::startGameLoop()
{
    Display display(board);
    Input input(board);
    std::array<std::string, 2> endMsg = {"GG EZ! You won!\n","LOL, so bad loser!\n"};
    std::string command;
    while(state == InProgress)
    {
        display.printBoard();
        std::cout << "Value: Row: Col:\n";
        getline(std::cin, command);
        input.handleInput(command);
        checkGameState();
    }
    std::cout << endMsg[state];
}