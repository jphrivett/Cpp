/* //Question 1:

#include <iostream>

struct Advertising
{
    int noAdsShown;
    double percentAdsClicked;
    double avgAmountEarnedPerAdClicked;
};

void printStruct(Advertising advertising)
{
    std::cout << "Number of ads shown is " << advertising.noAdsShown << std::endl;
    std::cout << "Percentage ads clicked is " << advertising.percentAdsClicked << std::endl;
    std::cout << "Average earned per clicked ad is " << advertising.avgAmountEarnedPerAdClicked << std::endl;

    double amountEarned = advertising.noAdsShown*(advertising.percentAdsClicked/100)*advertising.avgAmountEarnedPerAdClicked;
    std::cout << "Amount earned today is: " << amountEarned;
}

int main()
{

    Advertising advertising;

    std::cout << "Enter number of ads shown: " << std::endl;
    std::cin >> advertising.noAdsShown;

    std::cout << "Enter percentage ads clicked: " << std::endl;
    std::cin >> advertising.percentAdsClicked;

    std::cout << "Enter average earned per clicked ad: " << std::endl;
    std::cin >> advertising.avgAmountEarnedPerAdClicked;

    printStruct(advertising);

    return 0;
}*/

//Question 2:

#include <iostream>

struct Fraction
{
    int numerator;
    int denominator;
};

void printMultiplication(Fraction frac1, Fraction frac2)
{
    //Could also put the static_cast directly in these calculations:
    //double doubleNumerator1 = static_cast<double>(frac1.numerator);
    //double doubleNumerator2 = static_cast<double>(frac2.numerator);
    //double dec1 = doubleNumerator1/frac1.denominator;
    //double dec2 = doubleNumerator2/frac2.denominator;

    double dec1 = static_cast<double>(frac1.numerator)/frac1.denominator;
    double dec2 = static_cast<double>(frac2.numerator)/frac2.denominator;

    double multipliedFracs = dec1*dec2;
    std::cout << dec1 << "*" << dec2 << "=" << multipliedFracs;
}

int main()
{
    Fraction frac1;
    Fraction frac2;

    std::cout << "Enter numerator: ";
    std::cin >> frac1.numerator;

    std::cout << "Enter denominator: ";
    std::cin >> frac1.denominator;

    std::cout << "Enter another numerator: ";
    std::cin >> frac2.numerator;

    std::cout << "Enter another denominator: ";
    std::cin >> frac2.denominator;

    printMultiplication(frac1, frac2);
}
