#pragma once
#include <iostream>
#include <array>

#include "../Sources/board.cpp"
#include "../Sources/input.cpp"
#include "../Sources/display.cpp"


enum GameState
{
    InProgress = -1,
    Won,
    Lost
};
class Game
{
    public:
        Game();
        void startGameLoop();
        void checkGameState();
    private:
        Board board;
        GameState state;
};