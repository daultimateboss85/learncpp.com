/*
1a rvalue
b lvalue
c rvalue
d rvalue
e lvalue


2 76

3 accepts many more param types
    cant modify params

4 const pointers address cant ve changed, pointer to const cant change
    value of object being pointed to.

5
*/

#include <iostream>
#include <algorithm>

void sort2(int& x, int& y)
{
    if (x>y)
    {
        std::swap(x,y);
    }

    return;
}

int main()
{
    int x { 7 };
    int y { 5 };

    std::cout << x << ' ' << y << '\n'; // should print 7 5

    sort2(x, y); // make sure sort works when values need to be swapped
    std::cout << x << ' ' << y << '\n'; // should print 5 7

    sort2(x, y); // make sure sort works when values don't need to be swapped
    std::cout << x << ' ' << y << '\n'; // should print 5 7

    return 0;
}