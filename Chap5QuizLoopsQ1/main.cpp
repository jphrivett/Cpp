#include <iostream>
#include "constants.h"

// gets initial height from user and returns it
double getInitialHeight()
{
	std::cout << "Enter the height of the tower in meters: ";
	double initialHeight;
	std::cin >> initialHeight;
	return initialHeight;
}

// Returns height from ground after "seconds" seconds
double calculateHeight(double initialHeight, int seconds)
{
	// Using formula: [ s = u * t + (a * t^2) / 2 ], here u(initial velocity) = 0
	double distanceFallen = (myConstants::gravity * seconds * seconds) / 2;
	double currentHeight = initialHeight - distanceFallen;

	return currentHeight;
}

// Prints height every second till ball has reached the ground
void printHeight(double height, int seconds)
{
	if (height > 0.0)
	{
		std::cout << "At " << seconds << " seconds, the ball is at height:\t" << height <<
			" meters\n";
	}
	else
		std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

int main()
{
	const double initialHeight = getInitialHeight();

	int noSeconds = 0;

	/*double height = calculateHeight(initialHeight, noSeconds);

	while (height > 0.0)
    {
        printHeight(height, noSeconds++);
        height = calculateHeight(initialHeight, noSeconds);
    }

    printHeight(height, noSeconds);

    */

    //Or can use a do while loop:

    double height;

    do
	{
		height = calculateHeight(initialHeight, noSeconds);
		printHeight(height, noSeconds);
		++noSeconds;
	} while (height > 0.0);

	return 0;
}
