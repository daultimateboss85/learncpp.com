#define NOMINMAX
#include <iostream>
#include "Random.h"
#include <string_view>
#include <limits>
#include <windows.h>

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


bool hasUnextractedInput()
{
    return !std::cin.eof() && std::cin.peek() != '\n';
}


char getChar()
{
    char x{};

    while (true)
    {
        std::cin >> x;

        if(std::cin)
        {
            if (hasUnextractedInput()){
                ignoreLine();
                std::cout << "Just one character please: ";
                continue;
            }
            return x;
        }
        std::cin.clear();
        std::cout << "Bad input \n";
        ignoreLine();


    }
}
int getInt(){
    int x{};
    
    while(true){
        std::cin >> x;

        if (std::cin && !hasUnextractedInput())
        {
            return x;
        }
        if(std::cin.eof())std::exit(0);
        std::cout << "Rubbish input 😡\n";
        std::cin.clear();
        ignoreLine();

        std::cout << "Try again: ";
    }
}

int getNumber(int minBoundary, int maxBoundary)
{
    return Random::get(minBoundary, maxBoundary);
}

int getUserGuess(int guessNumber)
{
    int guess{};
    std::cout << "Guess #" << guessNumber << ": ";
    guess = getInt();
    return guess;
}

void printIntro(int minBoundary, int maxBoundary)
{
    std::cout << "Let's play a game. I'm thinking of a number between " << minBoundary << " and " << maxBoundary << "\n";
}

void printWinMessage()
{
    std::cout << "Correct! You win!\n";
}

void printTooHigh()
{
    std::cout << "Your guess is too high.\n";
}
void printTooLow()
{
    std::cout << "Your guess is too low.\n";
}
void printLoseMessage(int number)
{
    std::cout << "Sorry, you lose. The correct number was " << number << "\n";
}

char askPlayAgain()
{
    char playAgain{};
    do
    {
        std::cout << "Would you like to play again (y/n)? ";
        playAgain = getChar();
    } while (playAgain != 'y' && playAgain != 'n');

    return playAgain;
}

int getMaxGuesses()
{
    std::cout << "Enter your max guesses: ";
    int maxGuesses{getInt()};
    return maxGuesses;
}

int getBoundaryNumber(std::string_view boundary)
{
    int value{};
    std::cout << "Enter " << boundary << "value: ";
    value = getInt();
    return value;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    char stillPlaying{'y'};

    do
    {
        int guess{};
        int maxGuesses{getMaxGuesses()};
        int minBoundary{getBoundaryNumber("min")};
        int maxBoundary{getBoundaryNumber("max")};
        int number{getNumber(minBoundary, maxBoundary)};

        printIntro(minBoundary, maxBoundary);

        for (int guessNumber{1}; guessNumber <= maxGuesses; ++guessNumber)
        {
            guess = getUserGuess(guessNumber);
            if (guess == number)
            {
                printWinMessage();
                break;
            }
            else if (guess > number) printTooHigh();
            else printTooLow();

            if (guessNumber == maxGuesses) printLoseMessage(number);
            
        }

        stillPlaying = askPlayAgain();

    } while (stillPlaying == 'y');
    /*pick random number
    user is given seven guesses
    if guess is greater tell too high
    if less tell too low
    if all seven tries used tell them they lost and correct number
    if guessed tell great
    ask for y or n if they want to repeat game
    */
}