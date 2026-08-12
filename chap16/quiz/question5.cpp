#include <iostream>
#include <vector>
#include <string_view>
#include "../../headers/Random.h"

namespace WordList
{
    enum Words
    {
        mystery,
        broccoli, 
        account, 
        almost, 
        spaghetti, 
        opinion,
        beautiful, 
        distance, 
        luggage,
        count,
    };

    Words pickRandomWord()
    {
        return static_cast<Words>(Random::get(0,Words::count-1));
    }

    std::string_view getStringWord(Words word)
    {
        switch (word)
        {
            case mystery: return "mystery";
            case broccoli: return "broccoli";
            case account: return "account";
            case almost: return "almost";
            case spaghetti: return "spaghetti";
            case opinion: return "opinion";
            case beautiful: return "beautiful";
            case distance: return "distance";
            case luggage: return "luggage";
            default: return "error";
        }
    }

    void printWord(Words word)
    {
        std::cout << getStringWord(word);
    }
    
}

void printWelcome()
{
    std::cout << "Welcome to C++man (a variant of Hangman)\n";
    std::cout << "To win: guess the word. To lose: run out of pluses.\n\n";
}

int main()
{
    printWelcome();
    WordList::Words word{WordList::pickRandomWord()};

    std::cout << "The word is: " << WordList::getStringWord(word) << "\n";

}