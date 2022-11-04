#pragma once
#include <string>
#include <iostream>

class Input : public Validator
{
    public:
        Input(Board& board) : Validator(board.getBoard()), board(board) {}
        void handleInput(std::string command, std::string& msg);
    private:
        Board& board;
        bool validInput(int row, int col, int val);
        std::vector<std::string> split(std::string string, char delimeter);
        void insertOperation(const std::vector<std::string>& parameters, std::string& msg);
};