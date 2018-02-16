#include <iostream>
#include <string>

enum class Type
{
    OGRE,
    DRAGON,
    GIANT_SPIDER,
    SLIME
};

struct Monster
{
    Type type;
    std::string name;
    int health;
};

void printMonster(Monster monster)
{
    std::string type;

    if (monster.type == Type::OGRE)
        type = "ogre";
    else if (monster.type == Type::DRAGON)
        type = "dragon";
    else if (monster.type == Type::GIANT_SPIDER)
        type = "giant spider";
    else if (monster.type == Type::SLIME)
        type = "slime";
    else
        type = "???";


    std::cout << "This " << type << " is named "
    << monster.name << " and has " << monster.health
    << " health.\n";
}

int main()
{
    Monster monster1 {Type::OGRE, "Torg", 145};
    Monster monster2 {Type::SLIME, "Blurp", 23};

    printMonster(monster1);
    printMonster(monster2);

    return 0;
}
