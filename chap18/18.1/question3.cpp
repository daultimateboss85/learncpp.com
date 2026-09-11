#include <iostream>
#include <iterator>
#include <utility>

int main()
{
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };

    int swaps{};
    int length{static_cast<int>(std::size(array))};

    for (int i =0; i < length; ++i)
    {
        swaps = 0;
        
        for (int j=0; j < length - i - 1; ++j)
        {
            if( array[j] > array[j+1])
            {
                std::swap(array[j], array[j+1]);
                swaps++;
            }
        }

        if (swaps ==0)
        {
            std::cout << "Terminated on iteration " << i+1 << "\n";
            break;
        }
    }

    for (const auto& num: array)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";
}