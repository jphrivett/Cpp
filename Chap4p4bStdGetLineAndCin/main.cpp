#include <string>
#include <iostream>

int main()
{
    std::cout << "Enter your full name ";
    //std::string choice;
    //std::cin >> choice;
    int choice ;
    std::cin >> choice;

    //If you enter only one number here, for example 29 or
    //485776 or 394965946 etc. then you only need a 1 in the
    //ignore statement below:
    //This is because the entire number is transferred to the
    //variable and only the '\n' is left behind. Therefore it
    //is only the first character.
    //The entire number is treated as a single character.
    //But if you enter numbers separated by a space then you
    //need to ignore more characters:
    std::cin.ignore(10, '\n');

    //This is the biggest range you can specify that you are
    //sure will not overflow the function parameter which is
    //an int:
    //std::cin.ignore(32767, ' ');
    //Also seems to work with 1 for some reason!Ah, because ' '
    //is the first character in the string example! That's why!

    std::cout << "Now enter your birthplace: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Hello, " << choice <<
    ", you were born in " << name << '\n';

    return 0;
}

//2,147,483,647 is the max number you can enter for 32-bit int.
