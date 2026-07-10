#include <iostream>
#include <vector>

int main()
{
    std::vector<char> arr{'h', 'e', 'l', 'l', 'o'};

    std::cout << "The array has " << std::size(arr) << "elements." << "\n";
    std::cout << arr[1] << arr.at(1) << "\n";

}

/*
2a size_type is an alias for something which is a large unsigned integral type

b size_t it us unsigned

c .size and std::size()*/