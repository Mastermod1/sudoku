class Validator
{
    public:
        Validator(Board& board) : board(board) {}
    protected:
        bool valueNotInRow(int row, int value);
        bool valueNotInCol(int col, int value);
        bool valueNotInSquare(int row, int col, int value);
    private:
        Board& board;
};