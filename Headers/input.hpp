#pragma once
#include <iostream>

class Input : public Validator
{
    public:
        Input(Board& board) : Validator(board.getBoard()), board(board) {}
        void handleInput(int row, int col, int val);
    private:
        Board& board;
        bool validateInput(int row, int col, int val);
};