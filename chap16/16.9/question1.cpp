#include <iostream>
#include <vector>
#include <cassert>

namespace Animals
{
    enum names
    {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_names,
    };
};

int main()
{
    std::vector<int> legs(Animals::max_names);
    legs = {2,4,4,4,2,0};

    assert(legs.size() == Animals::max_names);

    std::cout << legs[Animals::elephant] << "\n";
}