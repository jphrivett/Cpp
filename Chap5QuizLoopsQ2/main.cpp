//Things to improve for next time:
//Think more carefully about what exactly should go in
//each function to make it most useful in general.
//For example maybe put cout and cin in same function, even
//if it means passing in another parameter.
//Don't type numbers into functions for game parameters,
//include them as parameters in the functions so you can
//easily change them later.
//You don't need to call the seed for rand() every time,
//you can just call rand() multiple times and it will give
//different values.

//This:
/* if (answer == 'y')
        return 1;
    else
        return 0; */

//Can be written much nicer as this:
// return (answer == 'y');

#include <iostream>
#include <cstdlib>
#include <ctime>

int getRandomNumber(int min, int max)
{
    static const double frac = 1.0/(static_cast<double>(RAND_MAX) + 1.0);;

    return min + static_cast<int>((max-min+1)*rand()*frac);
}

int getGuess()
{
    int guess;

    while (true)
    {
        std::cin >> guess;

        if (std::cin.fail() || (guess < 1) || (guess > 100))
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout << "Invalid input, please try again: ";
        }

        else
        {
            std::cin.ignore(32767,'\n');
            return guess;
        }
    }

}

void game()
{
    srand(static_cast<unsigned int>(time(0)));

    //Run it once to remove dodgy first number which isn't
    //random. Then use value from second run:
    getRandomNumber(1,100);
    int noToGuess = getRandomNumber(1,100);

    std::cout << "Lets play a game. I'm thinking of a "
              << "number between 1 and 100."
              << "You have 7 tries to guess it:\n";

    int counter = 1;
    int guess;

    while (counter <= 7)
    {
        std::cout << "Guess #" << counter << ": ";
        guess = getGuess();

        if (guess == noToGuess)
        {
            std::cout << "Correct! You win!\n";
            return;
        }
        else
        {
            if (guess < noToGuess)
                std::cout << "Your guess is too low.\n";
            else
                std::cout << "Your guess is too high.\n";

            ++counter;
        }
    }

    std::cout << "Sorry, you lose, the correct number was "
              << noToGuess << "\n";

    return;
}

bool askUserToPlayAgain()
{
    static char answer;

    do
    {
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> answer;
    }
    while ((answer != 'y') && (answer != 'n'));

    /*switch (answer)
    {
        case 'y':
            return 1;
        default
            return 0;
    }*/

    if (answer == 'y')
        return 1;
    else
        return 0;

}

int main()
{

    do
    game();

    while (askUserToPlayAgain());
}
