/*
a)
problem is count goes up to the length of the array which is out of bounds
change to std::size(arr-1)
#include <array>
#include <iostream>

int main()
{
    std::array arr { 0, 1, 2, 3 };

    for (std::size_t count{ 0 }; count <= std::size(arr-1); ++count)
    {
        std::cout << arr[count] << ' ';
    }

    std::cout << '\n';

    return 0;
}

b)
problem is array decay 
when array is passed to printArray, array now becomes a pointer to the address of the first element in array
use pointer arithmetic of indexing not a for loop
#include <iostream>

void printArray(int array[])
{
    for (int element : array)
    {
        std::cout << element << ' ';
    }
}

int main()
{
    int array[] { 9, 7, 5, 3, 1 };

    printArray(array);

    std::cout << '\n';

    return 0;
}
    
c)
length of array should be known at compile time :)
use std::vector

#include <array>
#include <iostream>

int main()
{
    std::cout << "Enter the number of test scores: ";
    std::size_t length{};
    std::cin >> length;

    std::array<int, length> scores;

    for (std::size_t i { 0 } ; i < length; ++i)
    {
        std::cout << "Enter score " << i << ": ";
        std::cin >> scores[i];
    }
    return 0;
}
*/
