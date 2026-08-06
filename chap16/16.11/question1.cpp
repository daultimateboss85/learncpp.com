#include <iostream>
#include <vector>
#include <string_view>

void printStack(const std::vector<int>& stack)
{
    std::cout << "(Stack:";

    if (stack.empty())
    {
        std::cout << "empty";
    }

    else
    {
        for(auto num: stack)
        {
            std::cout << " " << num; 
        }
    }

    std::cout << ") \n";
}

void stackOperation(std::vector<int>& stack, std::string_view operation, int num=0)
{
    if (operation == "Push")
    {
        std::cout << "Push " << num << " ";
        stack.push_back(num);
    }

    else
    {
        std::cout << "Pop    ";
        stack.pop_back();
    }

    printStack(stack);
}
int main()
{
    std::vector<int> stack{};
    const std::string_view push{"Push"};
    const std::string_view pop{"Pop"};

    stackOperation(stack, push, 1);
    stackOperation(stack, push, 2);
    stackOperation(stack, push, 3);
    stackOperation(stack, pop);
    stackOperation(stack, push, 4);
    stackOperation(stack, pop);
    stackOperation(stack, pop);
    stackOperation(stack, pop);
    

}