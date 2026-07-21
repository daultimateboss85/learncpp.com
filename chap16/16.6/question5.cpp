#include <iostream>
#include <vector>

template<typename T>
T findMax(const std::vector<T>& arr)
{
    T largest{};
    if (arr.size() == 0)
    {
        return largest;
    }

    largest = arr[0];

    for (std::size_t index{0}; index < arr.size(); ++index)
    {
        if(arr[index] > largest)
        {
            largest = arr[index];
        }
    }

    return largest;
}


int main()
{
    std::vector data1 { 84, 92, 76, 81, 56 };
    std::cout << findMax(data1) << '\n';

    std::vector data2 { -13.0, -26.7, -105.5, -14.8 };
    std::cout << findMax(data2) << '\n';

    std::vector<int> data3 { };
    std::cout << findMax(data3) << '\n';

    return 0;
}
