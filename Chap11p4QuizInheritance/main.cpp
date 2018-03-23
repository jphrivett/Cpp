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

    std::string getName() const
    {
        return m_name;
    }

    std::string getColor() const
    {
        return m_color;
    }
};

class Apple : public Fruit
{
private:
    double m_fibre;

public:
    Apple(std::string name = "", std::string color = "", double fibre = 0.0)
        : Fruit(name, color), m_fibre{fibre}
    {

    }

    double getFibre() const
    {
        return m_fibre;
    }

    friend std::ostream& operator<<(std::ostream &out, const Apple &a);
};

class Banana : public Fruit
{
public:
    Banana(std::string name = "", std::string color = "")
        : Fruit(name, color)
    {

    }

    friend std::ostream& operator<<(std::ostream &out, const Banana &b);

};

std::ostream& operator<<(std::ostream &out, const Apple &a)
{
    out << "Apple (" << a.getName() << ", " << a.getColor() << ", " << a.getFibre() << ")\n";
    return out;
}

std::ostream& operator<<(std::ostream &out, const Banana &b)
{
    out << "Banana (" << b.getName() << ", " << b.getColor() << ")";
    return out;
}

int main()
{
	const Apple a("Red delicious", "red", 4.2);
	std::cout << a;

	const Banana b("Cavendish", "yellow");
	std::cout << b;

	return 0;
}
