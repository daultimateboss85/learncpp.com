#include <string>
#include <iostream>
#include "Random.h"

class Monster
{
public:
    
    enum Type
    {
        dragon,
		goblin,
		ogre,
		orc,
		skeleton,
		troll,
		vampire,
		zombie,
		maxMonsterTypes,
    };
    Monster(Type type, std::string_view name, std::string_view roar, int hitPoints)
    :m_type{type}
    ,m_name{name}
    ,m_roar{roar}
    ,m_hitPoints{hitPoints}
    {

    }

    std::string_view getTypeString() const
    {
        switch(m_type)
        {
            case dragon: return "dragon";
            case goblin: return "goblin";
            case ogre: return "ogre";
            case orc: return "orc";
            case skeleton: return "skeleton";
            case troll: return "troll";
            case vampire: return "vampire";
            case zombie: return "zombie";
            default:
                return "monster";
        }
    }

    void print() const
    {
        std::cout << m_name << " the " << getTypeString();
        
        if (m_hitPoints >0)
        {
            std::cout << " has " << m_hitPoints <<
        " hit points and says " << m_roar << "\n";
        }
        else
        {
            std::cout << " is dead" << "\n";
        }
       
    }

private:
    Type m_type {};
    std::string m_name {};
    std::string m_roar {};
    int m_hitPoints {};
};


namespace MonsterGenerator
{

    std::string_view getName(int name);
    std::string_view getRoar(int roar);

    Monster generate()
    {
        return Monster{

            static_cast<Monster::Type>(Random::get(0,8)), 
            getName(Random::get(0,5)),
            getRoar(Random::get(0,5)),
            Random::get(1,100)};
    }

    std::string_view getRoar(int roar)
    {
        switch (roar)
        {
        case 0: return "oink";
        case 1: return "bask";
        case 2: return "talk";
        case 3: return "bark";
        case 4: return "woof";
        case 5: return "screech";
        default: return "roar";
           
        }
    }

    std::string_view getName(int name)
    {
        switch (name)
        {
            case 0: return "zabimaru";
            case 1: return "zenbonzakura";
            case 2: return "chad";
            case 3: return "bankai";
            case 4: return "hollow";
            case 5: return "zanpakto";
            default: return "ichigo";
        }
    }
};

int main()
{
	Monster m{ MonsterGenerator::generate() };
	m.print();

	return 0;
}