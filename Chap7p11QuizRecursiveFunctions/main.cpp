#include <iostream>

/*//Iterative fibonacci sequence:
int fibonacci(int n)
{
    int next = 1;
    int current = 1;
    int prev = 1;

    if (n == 0)
        return 0;

    for (int count = 2; count < n; ++count)
    {
        next = current + prev;
        prev = current;
        current = next;
    }
    return next;
}

int main()
{

    for (int count=0; count < 13; ++count)
        std:: cout << fibonacci(count) << " ";

    return 0;
}*/

/*//Q1:
int factorial(int n)
{
    if (n == 0)
        return 1;

    return factorial(n - 1) * n;

}

int main()
{
    for (int i = 0; i < 7; ++i)
        std::cout << factorial(i) << ' ';

    return 0;
}*/

//Q2:
/*int sumInts(int x)
{
    if (x < 10)
        return x;
    else
        return sumInts(x / 10) + (x % 10);
}

int main()
{
    std::cout << sumInts(93427) << '\n';
    std::cout << (0 % 10);

    return 0;
}*/

//Q3:
void printBinaryDigits(unsigned int n)
{
    if (n == 0)
        return;

    printBinaryDigits(n / 2);
    std::cout << (n % 2);
}

void printBinary(int n)
{
    if (n == 0)
        std::cout << '0';
    else
        printBinaryDigits(static_cast<unsigned int>(n));
}

int main()
{
    //The bit representation of signed int -15 is exactly
    //the same as the bit representation of unsigned int
    //4294967281. Therefore you can simply static cast to
    //this number and use the function for unsigned ints.
    //std::cout << static_cast<unsigned int>(n) << '\n';
    //std::cout << static_cast<int>(static_cast<unsigned int>(n)) << '\n';

    int n = -15;

    printBinary(n);
}








