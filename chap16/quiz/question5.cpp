#include <iostream>
#include <vector>
#include <string_view>
#include "../../headers/Random.h"
#include <string>
#include <cctype>

namespace WordList
{
    // Define your list of words here
    std::vector<std::string_view> words{"mystery", "broccoli", "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage"};

    std::string_view getRandomWord()
    {
        return words[Random::get<std::size_t>(0, words.size() - 1)];
    }
}

class Session
{
private:
    std::string_view word{};

public:
    Session()
        : word{WordList::getRandomWord()}
    {
        std::cout << "Welcome to C++man (a variant of Hangman)\n";
        std::cout << "To win: guess the word.  To lose: run out of pluses.\n";
    }

    void displayState()
    {
        std::cout << "The word: " << std::string(word.size(), '-') << "\n";
    }

    bool acceptLetter()
    {
        char letter{};

        while (true)
        {
            std::cout << "Enter your next letter: ";
            std::cin >> letter;
            while (!std::cin)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "That wasnt a valid input. Try again.\n";
                continue;
            }

            if (!(std::isalpha(letter)))
            {
                std::cout << "That wasnt a valid input. Try again.\n";
                continue;
            }
            else
            {
                std::cout << "You entered: " << letter << "\n";
                return true;
            }
        }

        return true;
    }
};

int main()
{

    Session session{};
    session.displayState();
    session.acceptLetter();
    return 0;
}