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
        bool isSolveable(std::array<std::array<int, 9>, 9> grid, int row, int col);
        Board board;
        GameState state;
};