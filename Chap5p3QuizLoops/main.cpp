#include <iostream>
#include <string>

/* //Q1:

int calculate(int x, int y, char c)
{
    switch(c)
    {
        case '+':
            return (x + y);
        case '-':
            return (x - y);
        case '*':
            return (x * y);
        case '/':
            return (x / y);
        case '%':
            return (x % y);
        default:
            std::cout << "Invalid operator\n";
            return 0;
    }

}

int main()
{
    std::cout << "Enter two integers and a mathematical operation:\n";
    int x;
    int y;
    char c;
    std::cin >> x;
    std::cin >> y;
    std::cin >> c;

    std::cout << calculate(x,y,c);

    return 0;
} */

//Q2

enum class Animal
{
    PIG,
    CHICKEN,
    GOAT,
    CAT,
    DOG,
    OSTRICH
};

std::string getAnimalName(Animal animal)
{
    switch (animal)
    {
        case Animal::PIG:
            return "pig";
        case Animal::CHICKEN:
            return "chicken";
        case Animal::GOAT:
            return "goat";
        case Animal::CAT:
            return "cat";
        case Animal::DOG:
            return "dog";
        case Animal::OSTRICH:
            return "ostrich";
        default:
            return "unidentified animal";
    }
}

int printNumberOfLegs(Animal animal)
{
    switch (animal)
    {
        /*case Animal::PIG:
            return 4;
        case Animal::CHICKEN:
            return 2;
        case Animal::GOAT:
            return 4;
        case Animal::CAT:
            return 4;
        case Animal::DOG:
            return 4;
        case Animal::OSTRICH:
            return 2;
        default:
            std::cout << "unidentified ";
            return 0;*/

        //Do not have to have individual returns for each
        //case, can also do this:
        case Animal::CHICKEN:
        case Animal::OSTRICH:
            return 2;
        case Animal::PIG:
        case Animal::GOAT:
        case Animal::CAT:
        case Animal::DOG:
            return 4;
        default:
            std::cout << "unidentified ";
            return 0;

    }
}

int main()
{
    std::cout << "A " << getAnimalName(Animal::CAT) <<
    " has " << printNumberOfLegs(Animal::CAT) << " legs.\n";

    std::cout << "A " << getAnimalName(Animal::CHICKEN) <<
    " has " << printNumberOfLegs(Animal::CHICKEN) << " legs.\n";

}
