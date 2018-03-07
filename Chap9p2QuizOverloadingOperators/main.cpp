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
        reduce();
    }

    friend Fraction operator*(const Fraction &f, const int &i);
    friend Fraction operator*(const int &i, const Fraction &f);
    friend Fraction operator*(const Fraction &f1, const Fraction &f2);

    void print()
    {
        std::cout << m_numerator << "/" << m_denominator << "\n";
    }

    static int gcd(int a, int b)
    {
    return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
    }

    void reduce()
    {
        int divisor {gcd(m_numerator, m_denominator)};
        m_numerator /= divisor;
        m_denominator /= divisor;
    }

};

Fraction operator*(const Fraction &f, const int &i)
{
    return Fraction(f.m_numerator * i, f.m_denominator);
}

Fraction operator*(const int &i, const Fraction &f)
{
    return Fraction(f.m_numerator * i, f.m_denominator);
}

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}



int main()
{
    Fraction f1(2, 5);
    f1.print();

    Fraction f2(3, 8);
    f2.print();

    Fraction f3 = f1 * f2;
    f3.print();

    Fraction f4 = f1 * 2;
    f4.print();

    Fraction f5 = 2 * f2;
    f5.print();

    Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
    f6.print();

    return 0;
}
