#include <ios>
#include <iostream>
#include <limits>

int arr[]= {0, 1, 4, 9};

int main()
{
    int choice{};
    while (true)
    {
        bool found{false};
        std::cout << "Enter a single digit integer, or -1 to quit: ";
        std::cin >> choice;

        if(!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if (choice == -1)
        {
            std::cout << "Bye";
            return 0;
        }
        for (auto square: arr)
        {
            if (choice==square)
            {
                std::cout << choice << " is a perfect square\n";
                found = true;
                break;
            }
        }

        if (!found)
        {
            std::cout << choice << " is not a perfect square\n";
        }

    }
}