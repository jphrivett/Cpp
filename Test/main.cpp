#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

int main()
{
    srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock

    for (int count=1; count <= 100; ++count)
    {
        std::cout << rand() << "\t";

        // If we've printed 5 numbers, start a new row
        if (count % 5 == 0)
            std::cout << "\n";
	}

    return 0;
}
