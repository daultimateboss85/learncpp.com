#include <iostream>
#include <vector>
#include <string>
#include <string_view>

template <typename T>
bool isValueInArray(const std::vector<T>& arr, const T& value)
{
    for (const auto& element: arr)
    {
        if (element==value)
        {
            return true;
        }
    }

    return false;
}


int main()
{
    std::vector<std::string_view>names{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg","Holly"};

    std::cout << "Enter a name: ";

    std::string name{};
    std::cin >> name;

    bool found{false};

    found = isValueInArray<std::string_view>(names, name);

    std::cout << name;
    if (found) std::cout << " was found\n";
    else std::cout << " was not found\n";

}