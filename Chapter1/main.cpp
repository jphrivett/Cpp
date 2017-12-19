#include <iostream>

int readNumber();
void writeAnswer(int x);

int readNumber()
{
    std::cout << "Type an integer: ";
    int x;
    std::cin >> x;
    return x;
}

void writeAnswer(int x)
{
    std::cout << "The sum of these numbers is " << x;
}

int main()
{
    int int1 = readNumber();
    int int2 = readNumber();

    int summedInts = int1 + int2;

    writeAnswer(summedInts);
    return 0;

}


