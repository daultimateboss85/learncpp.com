#include <iostream>

class Fraction
{
int m_numerator{0};
int m_denominator{1};

public:

Fraction()=default;

Fraction(int numerator, int denominator)
    :m_numerator{numerator}
    ,m_denominator{denominator}
    {}

void getFraction()
{
    std::cout << "Enter a value for numerator: ";
    std::cin >> m_numerator;
    std::cout << "Enter a value for denominator: ";
    std::cin >> m_denominator;
    std::cout << '\n';
}

Fraction multiply(const Fraction& f2)
{
    return {m_numerator * f2.m_numerator, m_denominator * f2.m_denominator};
}

void printFraction() const
{
    std::cout << m_numerator << "/" << m_denominator << "\n";
}
};

int main()
{
    Fraction f1{};
    f1.getFraction();
    Fraction f2{};
    f2.getFraction();

    std::cout << "Your fractions multiplied together: ";

    f1.multiply(f2).printFraction();

    return 0;
}