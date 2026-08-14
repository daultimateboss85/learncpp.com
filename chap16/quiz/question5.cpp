#include <iostream>
#include <vector>
#include <string_view>
#include "../../headers/Random.h"
#include <string>
#include <cctype>

namespace WordList
{
    // Define your list of words here
    std::vector<std::string_view> words{ "distance", "luggage"};

    std::string_view getRandomWord()
    {
        return words[Random::get<std::size_t>(0, words.size() - 1)];
    }
}

class Session
{
private:
    std::string_view word{};
    std::vector<bool> guessedLetters {std::vector<bool>(26)};
    std::vector<char> incorrectGuesses{};
    int pluses {6};

public:
    std::string_view getWord() const{ return word;}

    // const std::vector<bool>& getguessedLetters() const  
    // {return guessedLetters;}
    const std::vector<char>& getIncorrectlyGuessed() const
    {
        return incorrectGuesses;
    }
    bool ifGuessed(char letter) const{return guessedLetters[static_cast<std::size_t>((letter % 32)-1)];}

    bool isInWord(char letter)
    {
        for (auto c: word)
        {
            if(c == letter)
            {return true;}
        }
        return false;
    }
    void usePlus(){pluses -=1;}
    bool plusRemains() const {return pluses >0;}
    int getPlus() const {return pluses;}

    void addGuess(char guess)
    {
        guessedLetters[static_cast<std::size_t>((guess % 32)-1)] = true;
    }

    void addIncorrectGuess(char letter)
    {
        incorrectGuesses.push_back(letter);
    }

    Session()
        : word{WordList::getRandomWord()}
    {
        std::cout << "Welcome to C++man (a variant of Hangman)\n";
        std::cout << "To win: guess the word.  To lose: run out of pluses.\n";
    }

    
};

void updateState( Session& s, char letter)
{
    s.addGuess(letter);

    if (s.isInWord(letter))
    {
        std::cout << "Yes, " << letter << " is in the word!";
    }
    else
    {
        std::cout << "No, " << letter << " is not in the word!";
        s.usePlus();
        s.addIncorrectGuess(letter);
    }
}
bool isGameOver(const Session& s)
{
    if (!s.plusRemains())
    {
        return true;
    }

    for (auto c: s.getWord())
    {
        if (!s.ifGuessed(c))
        {
            return false;
        }
    }
    return true;
}

bool isWon(const Session& s)
{
    if (!s.plusRemains())
    {
        return false;
    }
    return true;
}

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

        

        if (s.ifGuessed(letter))
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
       
        if (s.ifGuessed(c))
        {
            std::cout << c;
        }
        else
        {
            std::cout << '_';

        }
    }
    
        std::cout << "\tWrong guesses: ";
        std::cout << std::string( s.getPlus(), '+');
        for (auto c: s.getIncorrectlyGuessed())
        {
            std::cout << c;
        }

        std::cout << "\n";
    }




int main()
{

    Session session{};

    while(true)
    {
        draw(session);
        if (isGameOver(session))
        {
            if (isWon(session))
            {
                std::cout << "You won! The word was: " << session.getWord();
            }
            else
            {
                std::cout << "You lost! The word was: " << session.getWord();
            }
            break;
        };
        char guess{acceptLetter(session)};
        updateState(session, guess);
    }
    
    return 0;
}