//Q2:
/*#include <iostream>

class Average
{
private:
    int32_t m_sum = 0;
    int8_t m_number = 0;

public:
    Average(int32_t sum = 0, int8_t number = 0) : m_sum{sum}, m_number{number}
    {

    }

    Average& operator+=(int i);
    friend std::ostream& operator<<(std::ostream &out, const Average &average);

};

Average& Average::operator+=(int i)
{
    m_sum += i;
    ++m_number;
    return *this;
}

std::ostream& operator<<(std::ostream &out, const Average &a)
{
    out << (static_cast<double>(a.m_sum)/a.m_number);
    return out;
}

int main()
{
	Average avg;

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy = avg;
	std::cout << copy << '\n';

	return 0;
}*/

/*
//Q3:
#include <iostream>
#include <cassert>

class IntArray
{
private:
    int *m_array = nullptr;
    int m_size = 0;

public:
    IntArray(int s = 0) : m_size {s}
    {
        assert(m_size > 0);

        m_array = new int[m_size];

        for (int i = 0; i < m_size; ++i)
            m_array[i] = 0;
    }

    ~IntArray()
    {
        delete[] m_array;
    }

    IntArray(const IntArray &a)
    {
        m_size = a.m_size;

        m_array = new int[m_size];

        for (int i = 0; i < m_size; ++i)
            m_array[i] = a.m_array[i];
    }

    int& operator[](const int i) const
    {
        assert(i >= 0 && i < m_size);

        return m_array[i];
    }

    IntArray& operator=(const IntArray &a)
    {
        if (this == &a)
            return *this;

        delete[] m_array;

        m_size = a.m_size;

        m_array = new int[m_size];

        for (int i = 0; i < m_size; ++i)
            m_array[i] = a.m_array[i];

        return *this;
    }

    friend std::ostream& operator<<(std::ostream &out, const IntArray &a);

};

std::ostream& operator<<(std::ostream &out, const IntArray &a)
{
    for (int i = 0; i < a.m_size; ++i)
        out << a[i] << ' ';

    return out;
}

IntArray fillArray()
{
	IntArray a(5);
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a = fillArray();
	std::cout << a << '\n';

	IntArray b(1);
	a = a;
	b = a;

	std::cout << b << '\n';
	return 0;
}*/

//Q4:
#include <iostream>
#include <cmath>
#include <cassert>

class FixedPoint2
{
private:
    int16_t m_number = 0;
    int8_t m_fraction = 0;

public:
    FixedPoint2(int16_t number = 0, int8_t fraction = 0)
        : m_number{number}, m_fraction{fraction}
    {
        assert((fraction <= 99) && (fraction >= -99));

        if ((m_number < 0) || (m_fraction < 0))
        {
            if (m_number > 0)
                m_number = -m_number;

            if (m_fraction > 0)
                m_fraction = -m_fraction;
        }
    }

    FixedPoint2(double d)
    {
        m_number = static_cast<int16_t>(d);

        m_fraction = static_cast<int8_t>(round((d - m_number) * 100));

    }

    operator double() const
    {
        return (m_number + (static_cast<double>(m_fraction)/100));
    }

    FixedPoint2 operator-()
    {
        return FixedPoint2(-m_number, -m_fraction);
    }

    friend bool operator==(const FixedPoint2 &p1, const FixedPoint2 &p2);
    friend FixedPoint2 operator+(const FixedPoint2 &p1, const FixedPoint2 &p2);
    friend std::istream& operator>> (std::istream &in, FixedPoint2 &p);
};

std::ostream& operator<< (std::ostream &out, const FixedPoint2 &p)
{
    out << static_cast<double>(p);
    return out;
}

std::istream& operator>> (std::istream &in, FixedPoint2 &p)
{
    double d;
    in >> d;

    p = FixedPoint2(d);

    return in;
}

bool operator==(const FixedPoint2 &p1, const FixedPoint2 &p2)
{
    return ((p1.m_number == p2.m_number) && (p1.m_fraction == p2.m_fraction));
}

FixedPoint2 operator+(const FixedPoint2 &p1, const FixedPoint2 &p2)
{
    return FixedPoint2(static_cast<double>(p1) + static_cast<double>(p2));
}

void testAddition()
{
	// h/t to reader Sharjeel Safdar for this function
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.23) == FixedPoint2(1.98)) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.50) == FixedPoint2(2.25)) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.23) == FixedPoint2(-1.98)) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.50) == FixedPoint2(-2.25)) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.23) == FixedPoint2(-0.48)) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.50) == FixedPoint2(-0.75)) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.23) == FixedPoint2(0.48)) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.50) == FixedPoint2(0.75)) << '\n'; // first negative, possible decimal overflow
}

int main()
{
	testAddition();

	FixedPoint2 a(-0.48);
	std::cout << a << '\n';

	std::cout << -a << '\n';

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;

	std::cout << "You entered: " << a << '\n';

	return 0;
}



























