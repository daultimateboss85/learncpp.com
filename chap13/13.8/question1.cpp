#include <iostream>

struct AdRevenue
{
    int adsWatched{};
    double clicked{};
    double averageEarning{};
};


void printAdRevenue(AdRevenue& adRevenue)
{
    std::cout << "Ads watched: " << adRevenue.adsWatched << "\n";
    std::cout << "Percentage clicked: " << adRevenue.clicked << "\n";
    std::cout << "Average earnings: " << adRevenue.averageEarning << "\n";
    std::cout << adRevenue.adsWatched * adRevenue.clicked * adRevenue.averageEarning;
    std::cout << "\n";
}

int main()
{
    AdRevenue test{4, 20, 5};
    printAdRevenue(test);
}