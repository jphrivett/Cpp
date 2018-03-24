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

int main()
{
    std::cout << "Enter your name: ";
    std::string name;
    std::cin >> name;
    Player p(name);

    std::cout << "Welcome, " << p.getName() << ".\n";
    std::cout << "You have " << p.getHealth()
        << " health and are carrying " << p.getGold() << " gold.\n";

}





















