#include <iostream>

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
}
