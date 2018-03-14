//Q2:
#include <iostream>

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
}
