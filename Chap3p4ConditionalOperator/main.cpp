#include <iostream>

int getInt()
{
    std::cout << "Enter an integer: ";
    int x;
    std::cin >> x;
    return x;
}

bool isEven(int x)
{
    /*if ((x % 2) == 0)
        return true;
    else
        return false;*/

    // You can also write this like this:

    bool y = ((x % 2) == 0) ? true : false;
    return y;

}

// A simpler way to write this function is like this:

/*bool isEven(int x)
{
    return (x % 2) == 0;
}*/

void printResult(bool x)
{
    std::cout << "The integer is ";

    if (x == true)
        std::cout << "even.";
    else
        std::cout << "odd.";

}

int main()
{
    int enteredInt = getInt();
    bool isIntEven = isEven(enteredInt);
    printResult(isIntEven);

    return 0;
}
