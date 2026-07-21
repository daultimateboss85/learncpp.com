//Question 1
#include <iostream>
#include <vector>

template <typename T>
void printArray(std::vector<T>& v1)
{
    for(std::size_t index{0}; index < v1.size() ; index++)
        std::cout << v1[index] << " ";

    std::cout << "\n";
}

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
}

template <typename T>
T askNumber(const std::vector<T>& arr)
{
    T number;
    
    while(true)
    {
        std::cout << "Enter a number between 1 and 9: ";
        std::cin >> number;

        if (!std::cin)
            {
                std::cin.clear();
                ignoreLine();
                continue;
            }
        
        ignoreLine();
        
        if (!(number>=1 && number <=9))
        continue;

        return number;
    }
    
}
template <typename T>
int searchArray(std::vector<T> v1, T number)
{
    for (std::size_t index{0}; index < v1.size(); index++)
    {
        if (v1[index] == number)
        {
            return static_cast<int>(index);
        }
    }
    return -1;
}

int main()
{
    std::vector arr{ 4.4, 6.6, 7.7, 3.3, 8.8, 2.2, 1.1, 9.9 };

    auto number{askNumber(arr)};
    // Add your code here
    printArray(arr);

    int found{searchArray(arr, number)};

    std::cout << "The number " << number << " ";

    if (found == -1)
    {
        std::cout << "was not found" << "\n";
    }
    else
    {
        std::cout << "has index " << found << "\n";
    }
    return 0;
}