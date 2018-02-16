#include <iostream>
#include <cmath>

int printBinaryDigit(int x, int counter)
{
    if (counter == 3)
        std::cout << " ";

    double powOfTwo = pow(2.0,static_cast<double>(counter));
    int powOfTwoInt = static_cast<int>(powOfTwo);
    if (x >= powOfTwoInt)
    {
        std::cout << 1;
        return (x - powOfTwoInt);
    }

    else
    {
        std::cout << 0;
        return x;
    }

}

int main()
{

    std::cout << "Enter an integer between 0 and 255: ";
    int x;
    std::cin >> x;

    int counter{7};
    while (counter >= 0)
    {
        x = printBinaryDigit(x, counter);
        --counter;
    }

    return 0;
}
