#include "../Sources/validator.cpp"
#include <iostream>

class Input : public Validator
{
    public:
        Input(Board& board) : Validator(board) {}
        void handleInput(int row, int col, int val);
    private:
        bool validateInput(int row, int col, int val);
};