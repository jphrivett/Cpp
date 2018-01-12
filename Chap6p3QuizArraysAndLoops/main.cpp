#include <iostream>

//Q1:
/*int main()
{
    int array[] = {4,6,7,3,8,2,1,9,5};
    int arrayLength = sizeof(array)/sizeof(array[0]);

    for (int counter = 0; counter < arrayLength; ++counter)
    {
        std::cout << array[counter];
    }

    return 0;
}*/

//Q2:
/*int getNumber()
{
    while (true)
    {
        std::cout << "Enter a number between 1 and 9: ";
        int number;
        std::cin >> number;

        if (std::cin.fail() || number < 1 || number > 9)
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Invalid, try again: \n";
        }
        else
        {
            std::cin.ignore(32767, '\n');
            return number;
        }

    }
}

void printArray(int number)
{
    int array[] = {4,6,7,3,8,2,1,9,5};
    int arrayLength = sizeof(array)/sizeof(array[0]);

    std::cout << "The array is: ";
    for (int counter = 0; counter < arrayLength; ++counter)
    {
        std::cout << array[counter] << ' ';
    }

    int element = 0;
    while (array[element] != number)
        ++element;

    std::cout << "This value has index: " << element;
}

int main()
{
    int number = getNumber();

    printArray(number);

}*/

//Q3:

int main()
{
    int scores[] = { 84, 92, 76, 81, 56 };
    const int numStudents = sizeof(scores) / sizeof(scores[0]);

    int maxIndex = 0; // keep track of our largest score

    // now look for a larger score
    for (int student = 0; student < numStudents; ++student)
        if (scores[student] > scores[maxIndex])
            maxIndex = student;

    std::cout << "The best score was " << scores[maxIndex] << '\n';

    return 0;
}







