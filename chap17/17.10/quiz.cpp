#include <iostream>
/*
go to pointer to first letter of string
while the object at pointer is not a null terminator 
print object and increase pointer
*/
void printString(const char arr[])
{
    const char* ptr{arr};

    while (*ptr != '\0')
    {
        std::cout << *ptr;
        ++ptr;
    }

    std::cout << '\n';

}

void printStringBack(const char arr[])
{
/*we will move pointer to end of string then start moving pointer backwards and printing*/

    const char* beginning{arr};
    const char* end{arr};

    while(*end != '\0')
    {
        ++end;
    }

    --end;

    while (end+1 != beginning)
    {
        std::cout << *end;
        --end;
    }
}

int main()
{
    printString("Hello, world!");
    printStringBack("Hello, world!");
}