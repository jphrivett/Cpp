#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

std::string getName(int number)
{
    std::cout << "Enter name " << number << ": ";
    std::string name;
    //std::cin >> name; This doesn't work with spaces.
    //Need to use getline instead;
    std::getline(std::cin, name);
    return name;
}

void printArray(std::string *names, int number)
{
    for (int array = 0; array < number; ++array)
    {
        std::cout << "Name " << array + 1
                  << ": " << names[array] << '\n';
    }
}

void sortArray(std::string *array, int arrayLength)
{
    //std::sort(array, array + arrayLength);

    for (int counter = 0; counter < arrayLength - 1; ++counter)
    {
        int smallestElement = counter;

        for (int element = counter + 1; element < arrayLength; ++element)
        {
            if (array[element] < array[smallestElement])
                smallestElement = element;

        }

        std::swap(array[counter],array[smallestElement]);

    }

}

int main()
{
    std::cout << "How many names do you want to enter? ";
    int number;
    std::cin >> number;
    std::cin.ignore(1, '\n');

    std::string *names = new std::string[number];

    for (int array = 0; array < number; ++array)
    {
        names[array] = getName(array + 1);
    }

    //printArray(names, number);

    sortArray(names, number);

    printArray(names, number);

    delete[] names;
    names = nullptr;

    return 0;
}
