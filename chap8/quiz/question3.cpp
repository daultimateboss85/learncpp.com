#include <iostream>
#include "Random.h"
#include <string_view>

int getNumber(int minBoundary, int maxBoundary)
{
    return Random::get(minBoundary, maxBoundary);
}

int getUserGuess(int guessNumber)
{
    int guess{};
    std::cout << "Guess #" << guessNumber << ": ";
    std::cin >> guess;
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
        std::cin >> playAgain;
    } while (playAgain != 'y' && playAgain != 'n');

    return playAgain;
}

int getMaxGuesses()
{
    int maxGuesses{};
    std::cout << "Enter your max guesses: ";
    std::cin >> maxGuesses;
    return maxGuesses;
}

int getBoundaryNumber(std::string_view boundary)
{
    int value{};
    std::cout << "Enter " << boundary << "value: ";
    std::cin >> value;
    return value;
}

int main()
{
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