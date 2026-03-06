#define NOMINMAX
#include <iostream>
#include <cassert>
#include <limits>
#include <windows.h>
#include <cstdlib> 
#include <cstdint>

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool hasUnextractedInput()
{
    return !std::cin.eof() && std::cin.peek()!='\n';
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int16_t x{};
    // assert(false && "hehhe");
    // static_assert(false,"hehheheh");
    while(true)
    {
        std::cout << "give me some input: ";
        std::cin >> x;

        if(!std::cin)
        {
            if (std::cin.eof()){std::exit(0);}
            std::cout << "Bad input 😡 \n";
            std::cin.clear();
            ignoreLine();
        }
        else if(hasUnextractedInput())
        {
            std::cout << "Bad input 😡 \n";
            ignoreLine();

        }
        else
        {    
            std::cout << "Good input 😊\n";
        }

        std::cout << "You gave me " << x << "\n";
    }
}