#include <ios>
#include <iostream>
#include <array>
#include <limits>
#include <string_view>
#include <vector>
#include "..\..\headers\Random.h"

namespace Potion
{

    enum Type
    {
        healing,
        mana,
        speed,
        invisibility,
        max_potions
    };

    constexpr std::array types{healing, mana, speed, invisibility};
    constexpr std::array costs{20, 30, 12, 50};
    
    using namespace std::string_view_literals;

    constexpr std::array names{"healing"sv, "mana"sv, "speed"sv, "invisibility"sv};


    

    
}

void shop()
{
    std::cout << "\n";
    std::cout << "Here is our selection for today:\n";

    for (auto p: Potion::types)
    {
        std::cout << p <<  ") " << Potion::names[p] << " costs " << Potion::costs[p] << "\n";
    }
}

char getValidInput(std::vector<char> validOptions)
{
    char option{};
    while(true)
    {
        std::cin >> option;

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Try again: ";
            continue;
        }

        if (!std::cin.eof()&&std::cin.peek()!='\n')
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Try again: ";
            continue;
        }

        
        for (auto validOption: validOptions)
        {
            if(option==validOption)
            {
                return option;
            }
        }
        std::cout << "Try again: ";

    }
    
}

class Player
{
private:
    std::string_view m_name{};
    int m_gold{Random::get(80, 120)};
    std::array<int,3> m_inventory{};

public:
    void updateName(std::string_view name)
    {
        m_name = name;
    }

    void displayInfo() const
    {
        std::cout << "Hello " << m_name << ", you have " << m_gold << " gold.\n";
    }

    void buy(int option)
    {
        Potion::Type type{static_cast<Potion::Type>(option)};
        int cost{Potion::costs[type]};
       
        if (m_gold >= cost)
        {
            m_gold -= cost;
            std::cout << "You purchased a potion of " << Potion::names[type] << ". You have " 
                << m_gold << " gold left.\n";
        }
        else {
            std::cout << "You can not afford that.\n";
        }
        
    }

};


int main()
{
    std::cout << "Welcom to Roscoe's potion emporium! \n";
    Player player{};
    std::cout << "Enter your name: ";
    
    std::string name;
    std::cin >> name;
    player.updateName(name);

    player.displayInfo();
    shop();

    while (true)
    {
        std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";

        char option{getValidInput(std::vector<char> {'0', '1', '2', '3', 'q'})};

        if (option=='q')
        {
            break;
        }

        player.buy(option-'0');
        shop();
        

    }

    std::cout << "Thanks for shopping at Roscoe's potion emporium!\n";

}