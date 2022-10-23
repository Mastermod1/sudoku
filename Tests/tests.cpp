#include "unit_test_framework.h"
#include "../Sources/solver.cpp"

// Solver tests from solver.hpp
TEST(SolvesSampleSudokuBoard)
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
}
// tabToPos(int row, int col) tests from board.hpp
TEST(TranslateTable5x3ValuesToFlatPos)
{
    int row = 5;
    int col = 3;

    ASSERT_EQUAL(tabToPos(row, col), 48);
}
TEST(TranslateTable8x8ValuesToFlatPos)
{
    int row = 8;
    int col = 8;

    ASSERT_EQUAL(tabToPos(row, col), 80);
}
TEST(TranslateTable1x0ValuesToFlatPos)
{
    int row = 1;
    int col = 0;

    ASSERT_EQUAL(tabToPos(row, col), 9);
}
TEST(TranslateTable0x8ValuesToFlatPos)
{
    int row = 0;
    int col = 8;

    ASSERT_EQUAL(tabToPos(row, col), 8);
}
TEST(TranslateTable0x0ValuesToFlatPos)
{
    int row = 0;
    int col = 0;

    ASSERT_EQUAL(tabToPos(row, col), 0);
}
// Board tests from board.hpp
TEST(InputValueLT0LeavesUnchangedBoard)
{
    Board board;
    int pos = 10;
    int value = -10;
    board.setCell(pos, value);
    ASSERT_EQUAL(board.getCell(pos), 0);
}
TEST(InputValueGT9LeavesUnchangedBoard)
{
    Board board;
    int pos = 10;
    int value = 20;
    board.setCell(pos, value);
    ASSERT_EQUAL(board.getCell(pos), 0);
}
TEST(CellValueIsSetable)
{
    Board board;
    int pos = 10;
    int value = 1;
    board.setCell(pos, value);
    ASSERT_EQUAL(board.getCell(pos), value);
}
TEST(ConstructedReturns0FilledBoard)
{
    Board board;
    for(int i = 0; i < 81; i++)
        ASSERT_EQUAL(board.getCell(i), 0);
}

TEST_MAIN()