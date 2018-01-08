#include <iostream>
#include <string>

double calcYearsPerLetter(std::string name, int age)
{
    double nameLength = name.length();
    double yearsPerLetter = age/nameLength;

    return yearsPerLetter;
}

int main()
{
    std::cout << "Enter your full name: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Enter your age: ";
    int age;
    std::cin >> age;

    double yearsPerLetter = calcYearsPerLetter(name, age);

    std::cout << "You've lived " << yearsPerLetter
              << " years for each letter in your name";

    return 0;
}
