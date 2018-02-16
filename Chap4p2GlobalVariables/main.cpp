#include <iostream>

//Initialise global variable x:
int x = 5;

void incrementAndPrint()
{
    int value = 1;
    ++value;
    std::cout << "incrementAndPrint = " << value << "\n";
}

void staticIncrementAndPrint()
{
    static int value = 1;
    ++value;
    std::cout << "staticIncrementAndPrint = " << value << "\n";
}

//Commonly use static variables to assign similar objects in a
//program with unique ID numbers:

int generateID()
{
    static int s_itemID = 0;
    return s_itemID++; // makes copy of s_itemID, increments the real s_itemID, then returns the value in the copy
}

int main()
{

    {
        //Declaring a new variable x with block scope:
        int x = 6;
        //This does change the value of x used outside the block.

        //This changes the value of the global variable x:
        x = 6;
    }

    std::cout << "x is: " << x << "\n";

    double getY();
    double y = getY();
    std::cout << "y is " << y << "\n";

    incrementAndPrint();
    incrementAndPrint();
    incrementAndPrint();

    staticIncrementAndPrint();
    staticIncrementAndPrint();
    staticIncrementAndPrint();

    return 0;
}
