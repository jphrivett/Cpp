#include <iostream>
#include <cassert>

class Matrix
{
private:
    double m_matrix[4][4];

public:
    Matrix()
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                m_matrix[i][j] = 0.0;
    }

    double& operator()(int row, int col);
    const double& operator()(int row, int col) const;
    void operator()();

    void print()
    {
        for (int i = 0; i < 4; ++i)
        {
             for (int j = 0; j < 4; ++j)
                std::cout << m_matrix[i][j] << ' ';

             std::cout << '\n';
        }

        std::cout << '\n';

    }

};

double& Matrix::operator()(int row, int col)
{
    assert(row >= 0 && row < 4);
    assert(col >= 0 && col < 4);

    return m_matrix[row][col];

}

const double& Matrix::operator()(int row, int col) const
{
    assert(row >= 0 && row < 4);
    assert(col >= 0 && col < 4);

    return m_matrix[row][col];

}

void Matrix::operator()()
{
    for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                m_matrix[i][j] = 0.0;

}

int main()
{
    Matrix matrix;
    matrix(2,3) = 5.3;
    matrix(1,1) = 3.2;

    matrix.print();

    matrix();

    matrix.print();
}
