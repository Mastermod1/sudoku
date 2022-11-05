#include "../Headers/input.hpp"

std::vector<std::string> Input::split(std::string string, char delimeter)
{
    std::vector<std::string> parts;
    std::string word = "";
    for(auto ch : string)
    {
        if(ch == delimeter)
        {
            if(word != "")
                parts.push_back(word);
            word = "";
            continue;
        }
        word += ch;
    }
    if(word != "")
        parts.push_back(word);
    return parts;
}

void Input::insertOperation(const std::vector<std::string>& parameters, std::string& msg)
{
    int val = std::stoi(parameters[1]);   
    int row = std::stoi(parameters[2]);
    int col = std::stoi(parameters[3]);

    std::string defaultInsertMsg= "Value: Row: Col:\n";
    msg = defaultInsertMsg;
    
    if(validInput(row, col, val))
        board.setCell(row, col, val);
    else
        msg = "Illegal move! Give it another try!\n" + defaultInsertMsg;
}

void Input::handleInput(std::string command, std::string& msg)
{
    auto commandParameters = split(command, ' ');
    char operationType = std::tolower(commandParameters[0].front());

    if(operationType == 'i')
        insertOperation(commandParameters, msg);
    if(operationType == 'q');
        quitOperation();
    if(operationType == 's');
        solveOperation();
}
void Input::quitOperation()
{
    exit(1);
}

void Input::solveOperation()
{

}

bool Input::validInput(int row, int col, int val)
{
    if(board.getCell(row, col) > 0)
        return false;
    if(val < 1 && val > 9)
        return false;
    return valueNotInRow(row, val) && valueNotInCol(col, val) && valueNotInSquare(row, col, val);
}