#include <iostream>

enum class MonsterType
{
    ogre,
    dragon,
    orc,
    giantSpider,
    slime,
};

struct Monster
{
    MonsterType monsterType;
    std::string name;
    int health;
};

std::ostream& operator<<(std::ostream& out,MonsterType& monsterType)
{
    using enum MonsterType;
    switch (monsterType)
    {
        case ogre:
            out << "Ogre";
            break;
        case dragon:
            out << "Dragon";
            break;
        case orc:
            out << "Orc";
            break;
        case giantSpider:
            out << "Giant Spider";
            break;
        case slime:
            out << "Slime";
            break;
    }
    return out;

}

void printMonster(Monster& monster)
{
    std::cout << "This " << monster.monsterType << " is named " <<
    monster.name << " and has " << monster.health << " health." << "\n"; 
}


int main()
{
    Monster torg{MonsterType::ogre, "Torg", 145};
    Monster blurp{MonsterType::slime, "Blurp", 23};

    printMonster(torg);
    printMonster(blurp);
}