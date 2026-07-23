#include <iostream>
#include <vector>
#include <string>
#include <string_view>
int main()
{
    std::vector<std::string_view>names{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg","Holly"};

    std::cout << "Enter a name: ";

    std::string name{};
    std::cin >> name;

    bool found{false};

    for(std::string_view arrName: names)
    {
        if (name==arrName)
        {
            found = true;
            break;
        }
    }

    std::cout << name;
    if (found) std::cout << " was found\n";
    else std::cout << " was not found\n";

}