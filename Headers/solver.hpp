#pragma once
#include <array>
#include "../Sources/validator.cpp"
#include "../Sources/board.cpp"
class Solver : public Validator
{
    public:
        Solver(Board& board) : Validator(board) {};

        bool solve(int, int);

    private:
        bool safeInsertOperation(int row, int col, int value);
};