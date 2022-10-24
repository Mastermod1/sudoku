#include "../Sources/board.cpp"
#include "../Sources/input.cpp"
#include "../Sources/display.cpp"
#include <iostream>


class Game
{
    public:
        Game();
        void startGameLoop();
    private:
        Board board;
};