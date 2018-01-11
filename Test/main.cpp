#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

int getRandomNumber(int min, int max)
{
    //The first output of rand() doesn't change much for
    //similar seed values, so when calling from clock it
    //gives very similar values. This effect is made worse
    //when the numbers are confined to the range 1 to 6.
    //Best thing to do is to ignore the first value and only
    //use from second value onwards.

    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
    // evenly distribute the random number across our range
    return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}

int main()
{
    srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock

    for (int count=1; count <= 100; ++count)
    {
        std::cout << getRandomNumber(1,6) << "\t";

        // If we've printed 5 numbers, start a new row
        if (count % 5 == 0)
            std::cout << "\n";
	}

    return 0;
}
