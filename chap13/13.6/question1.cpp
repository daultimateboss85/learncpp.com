#include <iostream>
#include <string_view>

enum class Animal{
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
};

constexpr std::string_view getAnimalName(Animal animal){
    switch (animal){
        case Animal::pig:
            return "pig";
        case Animal::chicken:
            return "chicken";
        case Animal::goat:
            return "goat";
        case Animal::cat:
            return "cat";
        case Animal::dog:
            return "dog";
        case Animal::duck:
            return "duck";
        default:
            return "error";
    }
}

void printNumberOfLegs(Animal animal)
{
    std::cout << "A " << getAnimalName(animal) << " has ";

    switch (animal)
    {
        case Animal::pig:
        case Animal::goat:
        case Animal::cat:
        case Animal::dog:
            std::cout << "4 legs.\n";
            break;
        case Animal::chicken:
        case Animal::duck:
            std::cout << "2 legs.\n";
            break;
        default:
            std::cout << "Error";
    }
}


int main(){
    printNumberOfLegs(Animal::cat);
    printNumberOfLegs(Animal::chicken);

}