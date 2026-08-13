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
    std::vector<char> guessedLetters {};

public:
    std::string_view getWord() const{ return word;}

    const std::vector<char>& getguessedLetters()  const
    {return guessedLetters;}

    void addGuess(char guess)
    {
        guessedLetters.push_back(guess);
    }

    Session()
        : word{WordList::getRandomWord()}
    {
        std::cout << "Welcome to C++man (a variant of Hangman)\n";
        std::cout << "To win: guess the word.  To lose: run out of pluses.\n";
    }

    
};

char acceptLetter( Session& s)
{
    char letter{};

    while (true)
    {
        std::cout << "Enter your next letter: ";
        std::cin >> letter;
        if(!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "That wasnt a valid input. Try again.\n";
            continue;
        }
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        bool already_guessed{false};
        for (auto guess: s.getguessedLetters())
        {
            if (letter== guess)
            {
                already_guessed = true;
                break;
            }
        }

        if (already_guessed)
        {
            std::cout << "You already guess that. Try again.\n";
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
            s.addGuess(letter);
            return letter;
        }
    }

    
}
void draw(const Session& s)
{
    std::cout << '\n';

    std::cout << "The word: ";
    for ([[maybe_unused]] auto c: s.getWord()) // step through each letter of word
    {
        bool found{false};

        for (auto letter: s.getguessedLetters())
        {
            if (c == letter)
            {
                std::cout << c;
                found = true;
                break;
            }
        }
        if (!found){std::cout << '_';}
    }

    std::cout << '\n';
}

int main()
{

    Session session{};

    for (int i=0; i < 6; i++)
    {
        draw(session);
        char guess{acceptLetter(session)};
    }
    
    return 0;
}