#include <iostream>
#include "constants.h"

double getTowerHeight()
{
    std::cout << "Enter tower height in meters: ";
    double towerHeight;
    std::cin >> towerHeight;

    return towerHeight;
}

double getBallHeight(double noSeconds, double towerHeight)
{
    double ballHeight = towerHeight
                      - (myConstants::gravity
                      * noSeconds * noSeconds)/2;
    if (ballHeight <= 0)
        ballHeight = 0;

    return ballHeight;
}

void printBallHeight(double noSeconds, double ballHeight)
{
    if (ballHeight == 0)
        std::cout << "At " << noSeconds << " seconds, the ball"
                  << " is on the ground.\n";
    else
        std::cout << "At " << noSeconds << " seconds, the ball"
                  << " is at height " << ballHeight
                  << " meters.\n";
}

int main()
{
    double noSeconds1 = 0;
    double noSeconds2 = 1;
    double noSeconds3 = 2;
    double noSeconds4 = 3;
    double noSeconds5 = 4;
    double noSeconds6 = 5;

    double towerHeight = getTowerHeight();

    double ballHeight1 = getBallHeight(noSeconds1,towerHeight);
    printBallHeight(noSeconds1,ballHeight1);

    double ballHeight2 = getBallHeight(noSeconds2,towerHeight);
    printBallHeight(noSeconds2,ballHeight2);

    double ballHeight3 = getBallHeight(noSeconds3,towerHeight);
    printBallHeight(noSeconds3,ballHeight3);

    double ballHeight4 = getBallHeight(noSeconds4,towerHeight);
    printBallHeight(noSeconds4,ballHeight4);

    double ballHeight5 = getBallHeight(noSeconds5,towerHeight);
    printBallHeight(noSeconds5,ballHeight5);

    double ballHeight6 = getBallHeight(noSeconds6,towerHeight);
    printBallHeight(noSeconds6,ballHeight6);

    return 0;
}
