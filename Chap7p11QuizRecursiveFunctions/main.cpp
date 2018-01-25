#include <iostream>

/*//Iterative fibonacci sequence:
int fibonacci(int n)
{
    int next = 1;
    int current = 1;
    int prev = 1;

    if (n == 0)
        return 0;

    for (int count = 2; count < n; ++count)
    {
        next = current + prev;
        prev = current;
        current = next;
    }
    return next;
}

int main()
{

    for (int count=0; count < 13; ++count)
        std:: cout << fibonacci(count) << " ";

    return 0;
}*/

int factorial(int n)
{
    if (n == 0)
        return 1;

    return factorial(n - 1) * n;

}

int main()
{
    for (int i = 0; i < 7; ++i)
        std::cout << factorial(i) << ' ';

    return 0;
}
