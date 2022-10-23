#include "../Headers/board.hpp"

void Board::setCell(int pos, int val){
    if(val > 9 or val < 0) 
        return; 
    board[pos] = val;
}
