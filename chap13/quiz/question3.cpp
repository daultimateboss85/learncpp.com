#include <iostream>

template<typename T>
struct Triad
{
    T memb1{};
    T memb2{};
    T memb3{};
};

template <typename T>
void print(const Triad<T>& triad)
{
    std::cout << "[" << triad.memb1 << ", " << triad.memb2 << ", " 
    << triad.memb3 << "]";
}
int main()
{
    Triad<int> t1{1,2,3};
    print(t1);
    Triad t2{1.2,3.4,5.6};
    print(t2);
}