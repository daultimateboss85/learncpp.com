#include <array>
#include <iostream>
int main()
{
    std::array<double, 365> highTemp{};
    constexpr std::array hello {'h','e', 'l', 'l', 'o'};

    std::cout << hello[1];
}