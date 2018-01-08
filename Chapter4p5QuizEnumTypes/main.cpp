#include <iostream>

enum MonsterRaces
{
    MONSTER_ORCS,
    MONSTER_GOBLINS,
    MONSTER_TROLLS,
    MONSTER_OGRES,
    MONSTER_SKELETONS
};

int main()
{
    MonsterRaces monsterRace = MONSTER_GOBLINS;
    std::string monster;

    if (monsterRace == MONSTER_ORCS)
        monster = "orcs";
    else if (monsterRace == MONSTER_GOBLINS)
        monster = "goblins";
    else if (monsterRace == MONSTER_TROLLS)
        monster = "trolls";
    else
        monster = "other";

    std::cout << "The monsters are " << monster;
    return 0;
}
