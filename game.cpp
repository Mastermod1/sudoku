#include "Sources/solver.cpp"
#include "Headers/display.hpp"
#include <iostream>


int main()
{
    Board board({
    0,0,0,3,0,0,0,0,0,
    3,0,9,7,2,6,0,0,8,
    2,0,6,8,0,0,3,0,4,
    0,3,2,0,7,0,5,0,0,
    0,0,8,1,6,0,0,3,0,
    7,0,0,0,3,8,0,0,0,
    0,0,0,0,0,0,0,0,5,
    9,1,0,0,0,0,0,0,3,
    0,0,0,2,0,4,0,0,1
    });
    Solver solver(board);
    Display display(board);


    if(solver.solve())
        display.printBoard();
    else
        std::cout << "didn't solve\n";
}