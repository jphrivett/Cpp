#include <iostream>

typedef int (*arithmeticFcn)(int, int);

int getInt()
{
    while (true)
    {
        std::cout << "Enter an integer: ";
        int x;
        std::cin >> x;

        if (!(std::cin.fail()))
        {
            std::cin.ignore(32767,'\n');
            return x;
        }

        std::cin.clear();
        std::cin.ignore(32767,'\n');
    }
}

char getChar()
{
    while (true)
    {
        std::cout << "Enter '+', '-', '*' or '/': ";
        char x;
        std::cin >> x;

        if (x=='+'||x=='-'||x=='*'||x=='/')
        {
            std::cin.ignore(32767,'\n');
            return x;
        }

        std::cin.clear();
        std::cin.ignore(32767,'\n');
    }
}

int add(int x, int y)
{
    return (x + y);
}

int subtract(int x, int y)
{
    return (x - y);
}

int multiply(int x, int y)
{
    return (x * y);
}

int divide(int x, int y)
{
    return (x / y);
}

int main()
{

    int x = getInt();
    char op = getChar();
    int y = getInt();

    //std::cout << "You entered " << getInt() << '\n';
    //std::cout << "You entered " << getChar() << '\n';

    return 0;
}
