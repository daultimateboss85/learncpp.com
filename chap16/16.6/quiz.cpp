//Question 1
#include <iostream>
#include <vector>

void print(std::vector<int> v1)
{
    for(std::size_t index{0}; index < v1.size() ; index++)
        std::cout << v1[index] << " ";
        
    std::cout << "\n";
}

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    // Add your code here
    print(arr);

    return 0;
}