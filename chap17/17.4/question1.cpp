#include <array>
#include <iostream>
#include <string_view>

struct Item
{
    std::string_view name {};
    int gold {};
};

void printItem(const Item& item)
{
    std::cout << "A " << item.name << " costs " << item.gold << " gold. \n";
}
int main()
{
    constexpr std::array items {Item{"sword", 5}, Item{"dagger", 3}, Item{"club", 2}, Item{"spear", 7}};
    
    for (const auto& item: items)
    {
        printItem(item);
    }
    return 0;
}