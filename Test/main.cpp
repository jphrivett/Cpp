#include <iostream>
#include <cassert>

class Data
{
private:
    int m_array[5] {1,2,3,4,5};

public:
    Data()
    {

    }

    int& operator[] (const int index)
    {
        assert((index >= 0) && (index < 5));
        return m_array[2];
    }

    void print()
    {
        for (int i:m_array)
            std::cout << i << " ";

        std::cout << '\n';
    }

};

int main()
{
    Data data;
    data[2] = 50;
    data.print();

}
