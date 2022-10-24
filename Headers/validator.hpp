class Validator
{
    public:
        Validator(Board& board) : board(board) {}
        bool valueNotInRow(int row, int value);
        bool valueNotInCol(int col, int value);
        bool valueNotInSquare(int row, int col, int value);
        bool safeInsertOperation(int row, int col, int value);
    protected:
        Board& board;
};