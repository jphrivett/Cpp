#include <iostream>
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
