#include <iostream>
#include <vector>
#include <string_view>
using namespace std::literals::string_view_literals;

int main()
{
    std::vector a{2, 4, 6, 8, 10, 12};
    const std::vector b{1.2, 3.4, 5.6, 7.8};
    const std::vector<std::string_view> c{"Alex", "Brad", "Charles", "Dave"};
    std::vector d{12};
    std::vector<int> e(12);
} 