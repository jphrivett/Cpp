#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int x;
    std::cin >> x;

    std::cout << "Enter a larger integer: ";
    int y;
    std::cin >> y;

    if (y < x)
    {
        std::cout << "Swapping the values\n";

        int smallerInt = y;
        std::cout << "The smaller value is " << smallerInt
                  << "\n";

        int largerInt = x;
        std::cout << "The larger value is " << largerInt;

    }
    else
        std::cout << "The smaller value is " << x << "\n";
        std::cout << "The larger value is " << y;


    return 0;
}
