#include <vector>
#include <iostream>
#include <utility>
#include <cassert>


template<typename T>
constexpr std::size_t toUZ( T value)
{
    // static_assert(std::is_integral<T>() || std::is_enum<T>());
    return static_cast<std::size_t>(value);
}

template <typename T>
std::pair<int, int> vecToPair(const std::vector<T>& vector)
{
    assert(vector.size() >= 1);
    T min{vector[toUZ(0)]};
    T max{vector[toUZ(0)]};

    int min_index{0};
    int max_index{0};

    for (int i = 0; i < vector.size(); ++i)
    {
        T num{vector[toUZ(i)]};
        if (num > max)
        {
            max = num;
            max_index = i;
        }
        if (num < min) 
        {
            min = num;
            min_index = i;
        }
    }

    return std::pair(min_index, max_index);
}

template<typename T>
void printArray(const std::vector<T>& arr)
{
    std::cout << "With array ( ";

    for (auto item: arr)
    {
        std::cout << item << ", ";
    }

    std::cout << ")\n";
}

template<typename T>
void printAnswer(const std::vector<T>& vector)
{
    std::pair minMax{vecToPair(vector)};
    
    std::cout <<"The min element has index " <<std::get<0>(minMax) << " and value " 
    << vector[toUZ(std::get<0>(minMax))] << "\n";
    std::cout <<"The max element has index " <<std::get<1>(minMax) << " and value " 
    << vector[toUZ(std::get<1>(minMax))] << "\n";

    std::cout << "\n";
}

/*we want to accept user input


*/

bool fillVecWithInput(std::vector<int>& arr)
{
    bool first{true};
    int curr_number{};

    while (true)
    {
        std::cin >> curr_number;
        if (curr_number==-1)
        {
            if (first)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            arr.push_back(curr_number);
            first = false;
        }
    }
}

int main()
{
    std::vector<int> numbers{};
    std::cout << "Enter numbers to add (use -1 to stop): ";
    bool acceptInput{ fillVecWithInput(numbers)};

    if (acceptInput)
    {
        printArray(numbers);
        printAnswer(numbers);
    }
    else
    {
        std::cout << "Enter better";
    }

}