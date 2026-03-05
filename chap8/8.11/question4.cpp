#include <iostream>

void fizzbuzz(int num)
{
    for (int i{1}; i <=num; ++i)
    {
        if (!(i%3) && !(i%5)){std::cout << "fizzbuzz";}
        else if(!(i%3)){std::cout << "fizz";}
        else if(!(i%5)){std::cout << "buzz";}
        else{std::cout << i;}
        std::cout << "\n";

    }
}
int main()
{
fizzbuzz(15);
}