#include <iostream>
#include <array>
#include <cassert>

/*//Q1:
class Point3d
{
    double m_x;
    double m_y;
    double m_z;

public:
    void setValues(double x, double y, double z)
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }

    void print()
    {
        std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">\n";
    }

    bool isEqual(Point3d &point)
    {
        return (point.m_x == m_x && point.m_y == m_y && point.m_z == m_z);
    }

};

int main()
{
    //You cannot access these values like this because they are private:
    //Point3d point = {5.0, 6.0, 7.0};
    //Instead you have to use the member function setValues:
    //Point3d point;
    //point.setValues(1.0, 2.0, 3.0);
    //point.print();

    Point3d point1;
    point1.setValues(1.0, 2.0, 3.0);

    Point3d point2;
    point2.setValues(1.0, 2.0, 3.0);

    if (point1.isEqual(point2))
        std::cout << "point1 and point2 are equal\n";
    else
        std::cout << "point1 and point2 are not equal\n";

    Point3d point3;
    point3.setValues(3.0, 4.0, 5.0);

    if (point1.isEqual(point3))
        std::cout << "point1 and point3 are equal\n";
    else
        std::cout << "point1 and point3 are not equal\n";

    return 0;
}*/

//Q2:

class Stack
{
    std::array<int, 10> array;
    int length;

public:
    void reset()
    {
        array = {};
        length = 0;
    }

    bool push(int value)
    {
        if (length < 10)
        {
            array[length++] = value;
            return true;
        }
        else
            return false;
    }

    int pop()
    {
        assert(length != 0);
        return array[--length];
    }

    void print()
    {
        std::cout << "( ";

        for (int i = 0; i < length; ++i)
            std::cout << array[i] << ' ';

        std::cout << ")\n";
    }

};

int main()
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}
