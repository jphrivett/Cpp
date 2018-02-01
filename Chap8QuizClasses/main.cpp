/*//Q1:
#include <iostream>
#include <cmath>

class Point2d
{
private:
    double m_x;
    double m_y;

public:
    Point2d(double x = 0.0, double y = 0.0): m_x {x}, m_y {y}
    {
    }

    void print()
    {
        std::cout << "Point2d (" << m_x << ", " << m_y << ");\n";
    }

    friend double distanceFrom(const Point2d &p1, const Point2d &p2);

};

//You should not pass in classes by value, but by constant reference:
double distanceFrom(const Point2d &p1, const Point2d &p2)
{
    return sqrt((p1.m_x - p2.m_x)*(p1.m_x - p2.m_x) + (p1.m_y - p2.m_y)*(p1.m_y - p2.m_y));
}

int main()
{

    Point2d first;
    Point2d second(3.0, 4.0);
    first.print();
    second.print();
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

    return 0;
}*/

/*
//Destructor:
{
    delete[] m_data;

    //Don't need this because program ends here anyway, so pointer is destroyed:
    //m_data = nullptr;
}*/

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
    Monster(MonsterType type, std::string name, std::string roar, int hitPoints) :
        m_type {type},
        m_name {name},
        m_roar {roar},
        m_hitPoints {hitPoints}
    {
    }

    std::string getTypeString(MonsterType type) const
    {
        switch (type)
        {
            case Dragon: return "dragon";
            case Goblin: return "goblin";
            case Ogre: return "ogre";
            case Orc: return "orc";
            case Skeleton: return "skeleton";
            case Troll: return "troll";
            case Vampire: return "vampire";
            case Zombie: return "zombie";
            default: return "error";
        }
    }

    void print() const
    {
        std::cout << m_name << " the " << getTypeString(m_type)
                  << " has " << m_hitPoints
                  << " hit points and says "
                  << m_roar << '\n';
    }
};

class MonsterGenerator
{

public:

	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
		// evenly distribute the random number across our range
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

    static Monster generateMonster()
    {
        Monster::MonsterType type = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1));
        int hitPoints = getRandomNumber(1, 100);

        static std::string s_names[6] {"albrecht", "bob", "carl", "dan", "emily", "francis"};
        static std::string s_roars[6] {"arrg", "brrrag", "craaarg", "drrrrag", "eeeeeiii", "frrrrar"};

        return Monster{type, s_names[getRandomNumber(0, 5)], s_roars[getRandomNumber(0, 5)], hitPoints};
    }

};

int main()
{

	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // If using Visual Studio, discard first random value

	Monster m = MonsterGenerator::generateMonster();
	m.print();

    return 0;
}










