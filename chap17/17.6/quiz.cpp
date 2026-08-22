#include <iostream>
#include <array>
#include <string>
#include <string_view>



namespace Animal
{
    enum Type 
    {
        chicken,
        dog,
        cat,
        elephant, 
        duck, 
        snake,
        max_animals,
    };

    struct Data
    {
        std::string_view name{};
        int numLegs{};
        std::string_view sound{};
    };

    constexpr std::array dataArray
    {
        Data{"Chicken", 2, "Caw"},
        Data{"Dog", 4, "Bark"},
        Data{"Cat", 4, "Meow"},
        Data{"Elephant", 4, "Trumpet"},
        Data{"Duck", 2, "Bawk"},
        Data{"Snake", 0, "Hiss"}
    };

    static_assert(dataArray.size() == max_animals);
 
}





void printData(Animal::Data data)
{
    std::cout << "A " << data.name << " has " << data.numLegs << " legs and says "<< data.sound << "\n";
}

int findAnimal(std::string_view string)
{
    for (int i=0; i < Animal::max_animals; ++i)
    {
        if (string== Animal::dataArray[i].name)
        {
            return i;
        }
    }
    return -1;
}

void printInputData(int index)
{
    if (index != -1)
    {
        printData(Animal::dataArray[index]);
        std::cout << "\n";
        std::cout << "Here is the data for the rest of the animals: \n";

        for(const auto& data: Animal::dataArray)
        {
            if (data.name != Animal::dataArray[index].name)
            {
                printData(data);
            }
        }

    }

    else
    {
        std::cout << "That animal couldn't be found.\n\n";
        std::cout << "Here is the data for the rest of the animals: \n";

        for(const auto& data: Animal::dataArray)
        {
            printData(data);
        }

    }


}

int main()
{
    std::string input{};
    std::cout << "Enter an animal: ";
    
    std::cin >> input;

    int index{findAnimal(input)};
    printInputData(index);
}