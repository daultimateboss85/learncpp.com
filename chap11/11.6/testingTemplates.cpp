#include <iostream>

// int add(int x, int y)
// {
//     std::cout << x << " + " << y << " = ";
//     return x + y;
// }

template <typename T>
T add(T x ,double y)
{
    std::cout << x << " + " << y << " = ";
    return x + y;
}
// int add(double, double) = delete;

template <typename T>
T max( T x, T y)
{
    return x < y ? y : x;
} 


int main()
{
    double a{65.2};
   
    
    std::cout << add<float>( a, 4);
}