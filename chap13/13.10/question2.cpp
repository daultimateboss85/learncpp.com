#include <iostream>

struct Fraction
{
    int numerator{};
    int denominator{};
};

Fraction getFraction()
{
    int num{};
    int denum{};

    std::cout << "Enter a value for the numerator: ";
    std::cin >> num;

    std::cout << "Enter a value for the denominator: ";
    std::cin >> denum;

    return Fraction({num, denum});
}

void printFraction(const Fraction& fraction)
{
    std::cout << "Your fractions multiplied together: ";
    std::cout << fraction.numerator<< "/" << fraction.denominator;
}

Fraction operator*(Fraction x, Fraction y)
{
    return Fraction({x.numerator * y.numerator,x.denominator*y.denominator});
}


int main()
{
    printFraction(getFraction() * getFraction());
}

/*if returned by reference object will be destroyed once the funtion
goes out of scope. therefore references to it will be dangling*/