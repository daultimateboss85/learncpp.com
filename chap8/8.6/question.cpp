#include <iostream>

int get_number()
{
    int a;
    std::cout << "Enter a number: ";
    std::cin >> a ;
    return a;
}

int calculate(int a, int b, char operation)
{
    switch(operation)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;    
        
    default:
        return 0;
    }
}

char get_operation()
{
    char operation;
    std::cout << "Enter an operator: ";
    std::cin >> operation;
    return operation;
}
int main(){
    int a;
    int b;
    char operation;

    a = get_number();
    b = get_number();
    operation = get_operation();

    std::cout << calculate(a, b, operation) << "\n";
}