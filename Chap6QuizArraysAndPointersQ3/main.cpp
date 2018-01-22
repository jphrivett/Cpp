#include <iostream>

void swapInts(int &int1, int &int2)
{
    int temp = int1;

    int1 = int2;
    int2 = temp;
}

int main()
{
    int *array = new int[2] {6,10};

    std::cout << "Before swapping the ints are " << array[0] << " and "
              << array[1] << ".\n";
    swapInts(array[0],array[1]);

    std::cout << "After swapping the ints are " << array[0] << " and "
              << array[1] << ".\n";

    delete[] array;
    array = nullptr;

    return 0;
}
