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
    Input input(board);
    std::array<std::string, 2> endMsg = {"GG EZ! You won!\n","LOL, so bad loser!\n"};
    std::string command;
    std::string responseMessage = "Value: Row: Col:\n";
    while(state == InProgress)
    {
        display.printBoard(board);
        std::cout << responseMessage;
        getline(std::cin, command);
        input.handleInput(command, responseMessage);
        checkGameState();
    }
    std::cout << endMsg[state];
}