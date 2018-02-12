#include <iostream>

class idGenerator
{
    static int nextID;

public:
    static int getNextID();
};

int idGenerator::nextID = 1;

int idGenerator::getNextID()
{
    return nextID++;
}

int main()
{
    for (int i = 0; i < 6; ++i)
        std::cout << idGenerator::getNextID();
}

