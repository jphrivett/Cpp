#include <iostream>

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents = 0) : m_cents {cents}
    {
        //std::cout << "I have " << m_cents << " cents\n";
    }

    friend Cents operator+(const Cents &c1, const Cents &c2);
    friend Cents operator-(const Cents &c1, const Cents &c2);

    int getCents() const
    {
       return m_cents;
    }

};

Cents operator+(const Cents &c1, const Cents &c2)
{
    return Cents(c1.m_cents + c2.m_cents);
}

Cents operator-(const Cents &c1, const Cents &c2)
{
    return Cents{c1.m_cents - c2.m_cents};
}

int main()
{

    Cents c1{3};
    Cents c2{6};

    Cents sum = c1-c2;

    std::cout << "I have " << sum.getCents() << " cents.";

    return 0;

}
