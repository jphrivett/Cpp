#include <iostream>
//Q1:
/*int main()
{

    for (int counter{0}; counter <= 20; counter += 2)
        std::cout << counter << "\n";

    return 0;
}*/

//Q2:

int sumTo(int value)
{
    int sum = 0;
    for (int counter = 1; counter <= value; ++counter)
        sum += counter;

    return sum;
}

int main()
{
    std::cout << "Enter an integer: ";
    int value;
    std::cin >> value;

    std::cout << sumTo(value);

}
