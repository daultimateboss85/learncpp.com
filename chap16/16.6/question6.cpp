#include <iostream>
#include <vector>
#include <string_view>
#include <cassert>
int main()
{
    std::vector divisors{3, 5, 7, 11, 13, 17, 19};
    std::vector<std::string_view> words{"fizz", "buzz", "pop", "bang", "jazz", "pow", "boom"};

    
    assert(divisors.size() == words.size() && "Div and word arr size dont match");

    for (int num {1}; num < 22; num++)
    {
        bool found_divisor{false};
        for (std::size_t div_index{0}; div_index < divisors.size(); div_index++)
        {
            if (!(num%divisors[div_index]))
            {
                found_divisor = true;
                std::cout << words[div_index];
            }
        }

        if (!(found_divisor))
        {
            std::cout << num;
        }

        std::cout << "\n";
    }
}