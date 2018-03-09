/*#include <iostream>

class Point
{
private:
    int m_x;
    int m_y;
    int m_z;

public:
    Point(int x = 0, int y = 0, int z = 0):m_x{x},m_y{y},m_z{z}
    {

    }

    friend std::istream& operator>> (std::istream &in, Point &p);
    friend std::ostream& operator<< (std::ostream &out, const Point &p);

};

std::istream& operator>> (std::istream &in, Point &p)
{
    in >> p.m_x;
    in >> p.m_y;
    in >> p.m_z;

    return in;
}

std::ostream& operator<< (std::ostream &out, const Point &p)
{
    out << "(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
    return out;
}

int main()
{
    std::cout << "Enter a point: \n";

    Point point;
    std::cin >> point;

    std::cout << "You entered: " << point << '\n';

    return 0;
}*/

#include <iostream>

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents) { m_cents = cents; }

    // Overload Cents + int
    friend Cents operator+(const Cents &cents, int value);

    int getCents() { return m_cents; }

    // note: this function is not a member function!
    Cents operator+(int value)
    {
        return Cents(m_cents + value);
    }
};



int main()
{
	Cents cents1(6);
	Cents cents2 = cents1 + 2;
	std::cout << "I have " << cents2.getCents() << " cents.\n";

	return 0;
}
