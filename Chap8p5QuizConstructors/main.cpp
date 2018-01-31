#include <iostream>
#include <string>

/*class Ball
{
    //If you don't initialise here, you can initialise both in each constructor:
    std::string m_colour {"black"};
    double m_radius {10.0};

public:
    //Can pass std::string by constant reference:
    Ball(const std::string &colour)
    {
        m_colour = colour;
        m_radius = 10.0;
    }

    Ball(double radius)
    {
        m_colour = "black";
        m_radius = radius;
    }

    Ball(std::string colour, double radius)
    {
        m_colour = colour;
        m_radius = radius;
    }

    Ball()
    {
        m_colour = "black";
		m_radius = 10.0;
    }

    print()
    {
        std::cout << "Colour: " << m_colour << ", radius: " << m_radius << '\n';
    }
};*/

//With as few constructors as possible:
class Ball
{
    //If you don't initialise here, you can initialise both in each constructor:
    std::string m_colour {"black"};
    double m_radius {10.0};

public:
    Ball(double radius)
    {
        m_colour = "Black";
        m_radius = radius;
    }

    Ball(std::string colour = "Black", double radius = 10.0)
    {
        m_colour = colour;
        m_radius = radius;
    }

    print()
    {
        std::cout << "Colour: " << m_colour << ", radius: " << m_radius << '\n';
    }
};

int main()
{

        Ball def;
        def.print();

	Ball blue("blue");
	blue.print();

	Ball twenty(20.0);
	twenty.print();

	Ball blueTwenty("blue", 20.0);
	blueTwenty.print();

    return 0;
}
