#pragma once

#include <array>
#include "../Sources/board.cpp"

class Board
{
    public:
        Board()
        {

        }
    private:
        std::array<int, 81> board;
};