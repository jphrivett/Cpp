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
}
