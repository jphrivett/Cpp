#include <iostream>

/*void printCStr(char *array, int length)
{
    for (int i = 0; i < length; ++i)
        std::cout << array[i];
}

int main()
{
    char array[] {"Hello, world!"};

    int length = sizeof(array)/sizeof(array[0]);

    printCStr(array,length);

    return 0;
}*/

//Or:
void printCStr(const char *array)
{
    while (*array != '\0')
    {
        std::cout << *array;
        ++array;
    }

}

int main()
{
    char array[] {"Hello, world!"};

    printCStr(array);

    return 0;
}
