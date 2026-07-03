#include <iostream>
#include <vector>

int main()
{
    std::vector squares{1,4,9,16,25}; //question 1

    //question 2 line 1 initializes a vector with the element 5 and
    //line 2 intitializes a vector with capacity for 5 elements

    std::vector<float> temp(365); //question 3
    
    std::vector values{0,0,0};

    std::cout << "Enter 3 integers: ";
    std:: cin >> values[0] >> values[1] >> values[2];
    std::cout << "The sum is: " << values[0] + values[1] + values[2] << "\n";
    std::cout << "The product is " << values[0] * values[1] * values[2] << "\n";

    return 0;
}