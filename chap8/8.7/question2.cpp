#include <iostream>

int main()
{
    char start{'a'};

    while (start <= 'z')
    {
        std::cout << start << " " << static_cast<int>(start)<< "\n";
        ++start;
    }
    std::cout << "\n";
}