//Q2:
/*#include <iostream>
#include <string>

class Fruit
{
private:
    std::string m_name;
    std::string m_color;

public:
    Fruit(std::string name = "", std::string color = "")
        : m_name{name}, m_color{color}
    {

    }

    std::string getName()
    {
        return m_name;
    }

    std::string getColor()
    {
        return m_color;
    }
};

class Apple : public Fruit
{
public:
    Apple(std::string color = "red") : Fruit("apple", color)
    {

    }

protected:
    Apple(std::string name, std::string color) : Fruit(name, color)
    {

    }
};

class Banana : public Fruit
{
public:
    Banana(std::string color = "yellow") : Fruit("banana", color)
    {

    }

};

class GrannySmith : public Apple
{
public:
    GrannySmith() : Apple("granny smith apple", "green")
    {

    }

};

int main()
{
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}
*/

//Q3:
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Creature
{
protected:
    std::string m_name;
    char m_symbol;
    int m_health;
    int m_damage;
    int m_gold;

public:
    Creature(std::string name, char symbol, int health, int damage, int gold)
        : m_name{name}, m_symbol{symbol}, m_health{health}, m_damage{damage}, m_gold{gold}
        {

        }

    const std::string& getName() {return m_name;}
    char getSymbol() {return m_symbol;}
    int getHealth() {return m_health;}
    int getDamage() {return m_damage;}
    int getGold() {return m_gold;}

    void reduceHealth(int health)
    {
        m_health -= health;
    }

    bool isDead()
    {
        return m_health <= 0;
    }

    void addGold(int gold)
    {
        m_gold += gold;
    }
};

class Player : public Creature
{
private:
    int m_level {1};

public:
    Player(std::string name) : Creature(name,'@',10,1,0)
    {

    }
    void levelUp()
    {
        ++m_level;
        ++m_damage;
    }

    int getLevel() {return m_level;}

    bool hasWon() {return m_level >= 20;}

};

class Monster : public Creature
{

public:
    enum Type
    {
        DRAGON,
        ORC,
        SLIME,
        MAX_TYPES
    };

    struct MonsterData
    {
        std::string name;
        char symbol;
        int health;
        int damage;
        int gold;
    };

    static MonsterData monsterData[MAX_TYPES];
    static Monster getRandomMonster();

    Monster(Type type) : Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].health, monsterData[type].damage, monsterData[type].gold)
    {

    }
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 }
};

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0/(static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

Monster Monster::getRandomMonster()
{
    int type {getRandomNumber(0, MAX_TYPES - 1)};
    return Monster(static_cast<Type>(type));
}

void attackMonster(Monster &m, Player &p)
{
    m.reduceHealth(p.getDamage());
    std::cout << "You hit the " << m.getName() << " for " << p.getDamage()
        << " damage.\n";

    if (m.isDead())
    {
        std::cout << "You killed the " << m.getName() << ".\n";
        p.levelUp();
        std::cout << "You are now " << p.getLevel() << ".\n";
        p.addGold(m.getGold());
        std::cout << "You found " << m.getGold() << " gold.\n";

    }
}

void attackPlayer(Monster &m, Player &p)
{
    p.reduceHealth(m.getDamage());
    std::cout << "The " << m.getName() << " hit you for " << m.getDamage()
        << " damage.\n";
    std::cout << "You have " << p.getHealth() << "/10 health left.\n";
}

void fightMonster(Player &p)
{
    Monster m {Monster::getRandomMonster()};

    std::cout << "You have encountered a " << m.getName() << " "
        << m.getSymbol() << ".\n";

    while (true)
    {
        std::cout << "(R)un or (F)ight: ";
        std::string option;
        std::cin >> option;

        if (option == "R")
        {
            bool run {static_cast<bool>(getRandomNumber(0,1))};

            if (run)
            {
                std::cout << "You successfully fled.\n";
                break;
            }
            else
            {
                std::cout << "You failed to flee.\n";
                attackPlayer(m, p);
                if (p.isDead())
                    break;
            }
        }
        else
        {
            attackMonster(m, p);
            if (m.isDead() || p.hasWon())
                break;

            attackPlayer(m, p);
            if (p.isDead())
                break;
        }

    }

}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
	rand();

    std::cout << "Enter your name: ";
    std::string name;
    std::cin >> name;
    Player p (name);

    std::cout << "Welcome, " << name << "\n";

    while (true)
    {
        fightMonster(p);

        if (p.isDead())
        {
            std::cout << "You died at level " << p.getLevel()
                << " and with " << p.getGold() << " gold.\n";
            std::cout << "Too bad you can't take it with you!\n";
            break;
        }

        if (p.hasWon())
        {
            std::cout << "You won with " << p.getGold() << " gold!";
            break;
        }
    }

    return 0;
}




















