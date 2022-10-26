class Validator
{
    public:
        Validator(std::array<std::array<int, 9>, 9> grid) : grid(grid) {}
        bool valueNotInRow(int row, int value);
        bool valueNotInCol(int col, int value);
        bool valueNotInSquare(int row, int col, int value);
        bool safeInsertOperation(int row, int col, int value);
    protected:
        std::array<std::array<int, 9>, 9> grid;
};