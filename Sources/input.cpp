#include "../Headers/input.hpp"

void Input::handleInput(int row, int col, int val)
{
    if(validateInput(row, col, val))
        board.setCell(row, col, val);
    else
    {
        do
        {
            std::cout << "Illegal move! Give it another try!\n";
            std::cout << "Value: Row: Col:\n";
            std::cin >> val >> row >> col;
        } while(not validateInput(row, col, val));
        board.setCell(row, col, val);
    }
}

bool Input::validateInput(int row, int col, int val)
{
    if(board.getCell(row, col) > 0)
        return false;
    if(val < 1 && val > 9)
        return false;
    return valueNotInRow(row, val) && valueNotInCol(col, val) && valueNotInSquare(row, col, val);
}