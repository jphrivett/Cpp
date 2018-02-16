#include <iostream>

int readNumber()
{
    std::cout << "Type an integer: ";
    int x;
    std::cin >> x;
    return x;
}

void writeAnswer(int x)
{
    std::cout << "The sum of these numbers is "
              << x << std::endl;
}
