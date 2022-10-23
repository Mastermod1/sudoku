#include "unit_test_framework.h"
#include "../Headers/board.hpp"

TEST(InputValueLT0LeavesUnchangedBoard)
{
    Board board;
    int pos = 10;
    int value = -10;
    board.setCell(pos, value);
    ASSERT_EQUAL(board.cellValue(pos), 0);
}
TEST(InputValueGT9LeavesUnchangedBoard)
{
    Board board;
    int pos = 10;
    int value = 20;
    board.setCell(pos, value);
    ASSERT_EQUAL(board.cellValue(pos), 0);
}
TEST(CellValueIsSetable)
{
    Board board;
    int pos = 10;
    int value = 1;
    board.setCell(pos, value);
    ASSERT_EQUAL(board.cellValue(pos), value);
}
TEST(ConstructedReturns0FilledBoard)
{
    Board board;
    for(int i = 0; i < 81; i++)
        ASSERT_EQUAL(board.cellValue(i), 0);
}

TEST_MAIN()