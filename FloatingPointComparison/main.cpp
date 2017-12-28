#include <iostream>
#include <cmath>

bool approximatelyEqualAbsRel(double a, double b,
                              double absEpsilon,
                              double relEpsilon)
{
    double diff = fabs(a - b);
    if (diff <= absEpsilon)
        return true;

    return diff <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) *
                    relEpsilon);
}

int main()
{
    double a = 0.1*10-1.0;
    double b = 0.00000000000000005;
    std::cout << approximatelyEqualAbsRel(a,b,1e-12,1e-8);
    return 0;
}
