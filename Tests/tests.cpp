#include <iostream>
#include <queue>

std::queue<std::string> incorects;

void TEST(std::string testName, bool expr)
{
    if(expr)
        std::cout<<testName<<"\t CORRECT\n";
    else
    {
        std::cout<<testName<<"\t INCORRECT\n";
        incorects.push(testName + "\t INCORRECT\n");
    }
}

int main()
{
    TEST("WhenGivenTruePrintsCorrect", true);
    TEST("WhenGivenFalsePrintsIncorrect", false);
    TEST("WhenFalseExpPrintsIncorrect", 1 == 0);
    if(incorects.empty())
        std::cout << "### ALL TESTS PASSED! ALL GREEN ###\n";
    else
    {
        std::cout << "###########################\nThese tests didn't pass:\n";
        while(not incorects.empty())
        {
            std::cout << incorects.front();
            incorects.pop();
        }
        std::cout << "### NOT ALL TESTS PASSED! ###\n";
    }     
        

}