#include <iostream>

class Shape
{
public:
    virtual std::ostream& print(std::ostream &out) const = 0;

    friend std::ostream& operator<<(std::ostream &out, const Shape &s);

    virtual ~Shape() {}
};

std::ostream& Shape::print(std::ostream &out) const
{
    return out;
}

std::ostream& operator<<(std::ostream &out, const Shape &s)
{
    return s.print(out);
}

int main()
{

    return 0;
}
