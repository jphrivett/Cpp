#include <iostream>
#include <typeinfo>

enum class Items
{
    HEALTH,
    TORCH,
    ARROW,
    MAX_ITEMS
};

//Using reference:
int countTotalItems(const auto &array)
{
    int total {0};

    for (const int &numItem : array)
        total += numItem;

    return total;
}

//Using pointer:
/*int countTotalItems(int *array)
{
    int total {0};

    //This is treated as pointer addition and dereference by the complier:
    //std::cout << array[0];

    for (int counter = 0; counter < static_cast<int>(Items::MAX_ITEMS); ++counter)
        total += array[counter];

    return total;
}*/

int main()
{
    //Investigating array and pointer types:
    //int array [5] = { 9, 7, 5, 3, 1 };

    //std::cout << typeid(array).name() << '\n';
    //Either using [] or + 1 causes the array to decay into a pointer:
    //And when the compiler sees the subscript operator [], it actually
    //translates that into a pointer addition and dereference:
    //std::cout << typeid(&array[1]).name() << '\n'; // print memory address of array element 1
    //std::cout << typeid(array+1).name() << '\n'; // print memory address of array pointer + 1

    //std::cout << typeid(array[1]).name() << '\n'; // prints 7
    //std::cout << typeid(*(array+1)).name() << '\n'; // prints 7 (note the parenthesis required here)


    int items[] {2,5,10};

    std::cout << "You have " << countTotalItems(items) << " items.";

    return 0;
}
