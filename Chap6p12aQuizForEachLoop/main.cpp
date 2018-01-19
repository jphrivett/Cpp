#include <iostream>
#include <string>

//You can use (constant) references in for each loops, because information about
//the size of the array is retained:
/*void printNames(const auto &names)
{
    std::cout << sizeof(names) << '\n';

    std::cout << sizeof("HelloTest") << '\n';

    std::cout << sizeof(std::string) << '\n';

    for (const auto &eachName : names)
        std::cout << eachName << '\n';

}*/

//You cannot use pointers in for each loops, because the size of the array is not
//known:
/*void printNames(const auto *ptr)
{
    std::cout << sizeof(ptr) << '\n';
    std::cout << sizeof(*ptr) << '\n';

    for (const auto &eachName : *ptr)
        std::cout << eachName << '\n';

}*/

//You cannot use arrays passed in as parameters from other functions in for each
//loops, because actually a pointer is passed in, so this case is exactly the same
//as the case above and the size of the array is not known:
/*void printNames(const std::string names[])
{
    std::cout << sizeof(names) << '\n';
    std::cout << sizeof(*names) << '\n';

    for (const auto &eachName : *names)
        std::cout << eachName << '\n';

}*/

int main()
{
    const std::string names[] = {"Alexis","Betty","Caroline","Dave","Emily","Fred","Greg","Holly"};
    std::cout << "Enter a name: ";
    std::string name;
    std::cin >> name;

    //For investigating references and pointers:
    //printNames(names);

    bool found = 0;

    //Use a reference here for performance reasons. Using a reference simply
    //uses the value in the array. Using a variable would copy the information in
    //array element into the variable.
    for (const auto &eachName : names)
    {
        if (eachName == name)
        {
            found = 1;
            break;
        }
    }

    if (found)
        std::cout << name << " was found.";
    else
        std::cout << name << " was not found.";

    return 0;
}
