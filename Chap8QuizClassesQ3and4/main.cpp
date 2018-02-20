#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

class Monster
{
public:
    enum MonsterType
    {
    Dragon,
    Goblin,
    Ogre,
    Orc,
    Skeleton,
    Troll,
    Vampire,
    Zombie,
    MAX_MONSTER_TYPES
    };

private:
    MonsterType m_type;
    std::string m_name;
    std::string m_roar;
    int m_hitPoints;

public:
    Monster(MonsterType type, std::string name, std::string roar, int hitPoints) : m_type{type}, m_name{name}, m_roar{roar}, m_hitPoints{hitPoints}
    {

    }

    std::string getTypeString() const
    {
        switch (m_type)
        {
        case Dragon: return "Dragon";
        case Goblin: return "Goblin";
        case Ogre: return "Ogre";
        case Orc: return "Orc";
        case Skeleton: return "Skeleton";
        case Troll: return "Troll";
        case Vampire: return "Vampire";
        case Zombie: return "Zombie";
        }

        return "???";
    }

    void print() const
    {
        std::cout << m_name << " the " << getTypeString() << " has "
        << m_hitPoints << " hit points and says " << m_roar << "\n";
    }
};

class MonsterGenerator
{
public:

    static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

	static Monster generateMonster()
    {
        Monster::MonsterType type = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES-1));
        int hitPoints = getRandomNumber(1, 100);
        static std::string s_names[6] {"a", "b", "c", "d", "e", "f"};
        static std::string s_roars[6] {"aaa", "bbb", "ccc", "ddd", "eee", "fff"};
        std::string name = s_names[getRandomNumber(0, Monster::MAX_MONSTER_TYPES-1)];
        std::string roar = s_roars[getRandomNumber(0, Monster::MAX_MONSTER_TYPES-1)];

        return (Monster {type , name, roar, hitPoints});
    }

};

int main()
{
    srand(static_cast<unsigned int>(time(0)));
	rand();

	Monster m = MonsterGenerator::generateMonster();
	m.print();

    return 0;
}
