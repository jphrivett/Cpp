#include <iostream>

/*
//Q2
int main()
{

    char c = 'a';

    while (c <= 'z')
    {
        std::cout << "Letter " << c << " has ASCII code "
        << static_cast<int>(c) << "\n";
        ++c;

    }

    return 0;
}
*/

//Q3
/*int main()
{
    int outer = 5;

    while (outer >= 1)
    {
        int inner = outer;
        while (inner >= 1)
        {
            std::cout << inner-- << " ";
        }

        std::cout << "\n";
        --outer;
    }
}*/

//Q4
int main()
{
    int outer {1};

    while (outer <= 5)
    {
        int inner {5};
        while (inner >= 1)
        {
            if (inner > outer)
                std::cout << "  ";
            else
                std::cout << inner << " ";

            --inner;
        }
        ++outer;
        std::cout << '\n';
    }

}




