#include <iostream>

namespace Monsters{
    enum MonsterType{
        orc,
        goblin,
        troll,
        ogre,
        skeleton,
    };
}


int main()
{
    Monsters::MonsterType monster{Monsters::troll};

    std::cout << "He is a " << monster<< "\n";
}