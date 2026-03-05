#include <iostream>


void fizzbuzz(int num)
{
    for(int i{1}; i<=num; ++i)
    {
        bool printed{false};
        if (!(i%3)){std::cout << "fizz"; printed=true;}
        if (!(i%5)){std::cout << "buzz"; printed=true;}
        if (!(i%7)){std::cout << "pop"; printed=true;}
        if(!printed){std::cout << i;}
        
        std::cout << "\n";
    }
}

int main()
{
    fizzbuzz(150);
}