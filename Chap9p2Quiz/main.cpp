#include <iostream>

class Fraction
{
private:
    int m_numerator = 0;
    int m_denominator = 1;

public:
    Fraction(int numerator = 0, int denominator = 1) :
        m_numerator {numerator}, m_denominator {denominator}
    {

    }

    void print()
    {
        std::cout << m_numerator << "/" << m_denominator << "\n";
    }

};

int main()
{
    Fraction f1(1, 4);
    f1.print();

    Fraction f2(1, 2);
    f2.print();

    return 0;
}
