#include <iostream>

/*
Code for comparing integers:
bool isSame(int x, int y)
{
    return (x == y);
}
*/

bool isPrime(int x)
{
    if (x == 2)
        return true;
    if (x == 3)
        return true;
    if (x == 5)
        return true;
    if (x == 7)
        return true;
    else
        return false;
}


int main()
{
    std::cout << "Enter a single digit integer: ";
    int x;
    std::cin >> x;

    bool prime = isPrime(x);

    if (prime)
        std::cout << x << " is a prime number.\n";
    else
        std::cout << x << " is not a prime number.\n";

    // ASCII characters:
    char ch{97};
    std::cout << "Typed 97, prints: " << ch << "\n";

    std::cout << "Now it is an integer so prints: "
              << static_cast<int>(ch) << "\n";
    int i1 = static_cast<int>(ch);
    std::cout << i1;

    const double grav{9.8};
    //grav = 9;
    // not possible to reassign constants and they must be
    // initialised immediately or get compiler error.
    // But you can initialise constant from an already existing
    // variable.

    return 0;

    /*
    Code for comparing integers:

    std::cout << "Type an integer: ";

    int x;
    std::cin >> x;

    std::cout << "Type another integer: ";

    int y;
    std::cin >> y;

    //bool z;
    bool z = isSame(x,y);

    if (z)
        std::cout << x << " is the same as " << y << "\n";
    else
        std::cout << x << " is not the same as " << y << "\n";

    return 0;*/
}
