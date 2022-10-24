#include "../Sources/board.cpp"
#include "../Sources/input.cpp"
#include "display.hpp"
#include <iostream>


class Game
{
    public:
        Game();
        void startGameLoop();
    private:
        Board board;
        Input input;
};