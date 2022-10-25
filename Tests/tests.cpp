#include "unit_test_framework.h"
#include "../Sources/board.cpp"
#include "../Sources/validator.cpp"


// Validator
TEST(ValueNotInSquare)
{
    Board board(
        {{
            {3, 1, 6, 5, 7, 8, 4, 9, 0},
            {5, 2, 0, 0, 0, 0, 0, 0, 0},
            {4, 8, 7, 0, 0, 0, 0, 3, 1},
            {2, 0, 3, 0, 1, 0, 0, 8, 0},
            {9, 0, 0, 8, 6, 3, 0, 0, 5},
            {8, 5, 0, 0, 9, 0, 6, 0, 0}, 
            {1, 3, 0, 0, 0, 0, 2, 5, 0},
            {6, 0, 0, 0, 0, 0, 0, 7, 4},
            {0, 0, 5, 2, 0, 6, 3, 0, 0}
        }}
    );
    Validator validator(board);
    ASSERT_TRUE(validator.valueNotInSquare(8,0,7));
}
TEST(ValueNotInCol)
{
    Board board(
        {{
            {3, 1, 6, 5, 7, 8, 4, 9, 0},
            {5, 2, 0, 0, 0, 0, 0, 0, 0},
            {4, 8, 7, 0, 0, 0, 0, 3, 1},
            {2, 0, 3, 0, 1, 0, 0, 8, 0},
            {9, 0, 0, 8, 6, 3, 0, 0, 5},
            {8, 5, 0, 0, 9, 0, 6, 0, 0}, 
            {1, 3, 0, 0, 0, 0, 2, 5, 0},
            {6, 0, 0, 0, 0, 0, 0, 7, 4},
            {0, 0, 5, 2, 0, 6, 3, 0, 0}
        }}
    );
    Validator validator(board);
    ASSERT_TRUE(validator.valueNotInCol(0,7));
}
TEST(ValueNotInRow)
{
    Board board(
        {{
            {3, 1, 6, 5, 7, 8, 4, 9, 0},
            {5, 2, 0, 0, 0, 0, 0, 0, 0},
            {0, 8, 7, 0, 0, 0, 0, 3, 1},
            {0, 0, 3, 0, 1, 0, 0, 8, 0},
            {9, 0, 0, 8, 6, 3, 0, 0, 5},
            {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
            {1, 3, 0, 0, 0, 0, 2, 5, 0},
            {0, 0, 0, 0, 0, 0, 0, 7, 4},
            {0, 0, 5, 2, 0, 6, 3, 0, 0}
        }}
    );
    Validator validator(board);
    ASSERT_TRUE(validator.valueNotInRow(0,2));
}
TEST(SquaredCheckLikeInGamev2)
{
    Board board(
        {{
            {3, 0, 6, 5, 0, 8, 4, 0, 0},
            {5, 2, 0, 0, 0, 0, 0, 0, 0},
            {0, 8, 7, 0, 0, 0, 0, 3, 1},
            {0, 0, 3, 0, 1, 0, 0, 8, 0},
            {9, 0, 0, 8, 6, 3, 0, 0, 5},
            {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
            {1, 3, 0, 0, 0, 0, 2, 5, 0},
            {0, 0, 0, 0, 0, 0, 0, 7, 4},
            {0, 0, 5, 2, 0, 6, 3, 0, 0}
        }}
    );
    Validator validator(board);
    ASSERT_TRUE(validator.safeInsertOperation(0,1,1));
}
TEST(SquaredCheckLikeInGame)
{
    Board board(
        {{
            {3,0,6,0,0,0,0,0,0},
            {5,2,0,0,0,0,0,0,0},
            {0,8,7,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0}
        }}
    );
    Validator validator(board);
    ASSERT_TRUE(validator.safeInsertOperation(0,1,1));
}
TEST(SquaredCheck)
{
    Board board(
        {{
            {2,1,3,0,0,0,0,0,0},
            {4,0,5,0,0,0,0,0,0},
            {6,7,8,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0}
        }}
    );
    Validator validator(board);
    ASSERT_TRUE(validator.valueNotInSquare(1,1,9));
}
// Board tests from board.hpp
TEST(CellValueIsSetable)
{
    Board board;
    int row = 1;
    int col = 2;
    int value = 1;
    board.setCell(row, col, value);
    ASSERT_EQUAL(board.getCell(row, col), value);
}
TEST(ConstructedReturns0FilledBoard)
{
    Board board;
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            ASSERT_EQUAL(board.getCell(i, j), 0);
}

TEST_MAIN()