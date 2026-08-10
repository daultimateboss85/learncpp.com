#include <cassert>
#include <iostream>
#include <vector>

namespace Items
{
    enum Type
    {
        health_potion,
        torch,
        arrow,
        max_items
    };

    std::string_view getItemName(int item)
    {
        switch(item)
        {
            case 0: return "health potion";
            case 1: return "torch";
            case 2: return "arrow";
            default: return "error";
        }
    }
}

// Inventory items should have integral quantities, so we don't need a function template here
int countTotalItems(const std::vector<int>& inventory)
{
    int sum { 0 };
    for (auto e: inventory)
        sum += e;
    return sum;
}


void printItems(const std::vector<int>& inventory)
{
    for (int item=0; item < Items::max_items; item++)
    {
        std::cout << "You have " << inventory[item] << " " <<  Items::getItemName(item);
        if (inventory[item]>1){std::cout << "s ";}
        std::cout << "\n";
    }
}

int main()
{
    std::vector inventory { 1, 5, 10 };
    assert(std::size(inventory) == Items::max_items); // make sure our inventory has the correct number of initializers
    printItems(inventory);
    std::cout << "You have " << countTotalItems(inventory) << " total items\n";

    return 0;
}