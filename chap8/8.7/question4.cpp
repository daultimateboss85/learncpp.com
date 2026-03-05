#include <iostream>

int main()
{
    int outer{5};

    while (outer >= 1)
    {
        
        int space{outer-1};
        int number{5-space};

        while (space >= 1)
        {
            std::cout << "  ";
            --space;
        }

        while (number>=1)
        {
            std::cout << number << " ";
            --number;
        }

        std::cout << "\n";
        --outer;

    }
}