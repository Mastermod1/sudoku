#pragma once
#include <string>
#include <iostream>

class Input : public Validator
{
    public:
        Input(Board& board) : Validator(board.getBoard()), board(board) {}
        void handleInput(std::string command);
    private:
        Board& board;
        bool validInput(int row, int col, int val);
        std::vector<std::string> split(std::string string, char delimeter);
        void Input::insertOperation(const std::vector<std::string>& parameters);
};