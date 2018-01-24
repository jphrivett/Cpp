#include <iostream>

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

struct arithmeticStruct
{
    char op;
    arithmeticFcn ptr;
};

//Put the typedef just before where you need to use it,
//just like whenever you instantiate anything normally:
typedef int (*arithmeticFcn)(int, int);

arithmeticFcn getArithmeticFunction(char op)
{
    switch (op)
    {
    default:
    case '+': return add;
    case '-': return subtract;
    case '*': return multiply;
    case '/': return divide;
    }
}

int main()
{
    int x = getInt();
    char op = getChar();
    int y = getInt();

    arithmeticFcn ptr = getArithmeticFunction(op);
    //Don't need to dereference the pointer like this:
    //std::cout << (*ptr)(x, y);
    //The complier does it automatically like this:
    std::cout << ptr(x, y);

    //std::cout << "You entered " << getInt() << '\n';
    //std::cout << "You entered " << getChar() << '\n';

    return 0;
}
