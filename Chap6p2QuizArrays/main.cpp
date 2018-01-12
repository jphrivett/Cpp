#include <iostream>

// Q1: double temp[365] = { 0.0 };

namespace Animal
    {
        enum Animal
        {
            CHIKEN,
            DOG,
            CAT,
            ELEPHANT,
            DUCK,
            SNAKE,
            MAX_ANIMALS
        };
    }

int main()
{
    int legs[Animal::MAX_ANIMALS] {2,4,4,4,2,0};

    std::cout << legs[Animal::ELEPHANT];

    return 0;
}
