#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "bool:\t\t" << sizeof(bool) << " bytes" << std::endl;
    std::cout << "char:\t\t" << sizeof(char) << " bytes" << std::endl;
    std::cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes" << std::endl;
    std::cout << "char16_t:\t" << sizeof(char16_t) << " bytes" << std::endl; // C++11, may not be supported by your compiler
    std::cout << "char32_t:\t" << sizeof(char32_t) << " bytes" << std::endl; // C++11, may not be supported by your compiler
    std::cout << "short:\t\t" << sizeof(short) << " bytes" << std::endl;
    std::cout << "int:\t\t" << sizeof(int) << " bytes" << std::endl;
    std::cout << "long:\t\t" << sizeof(long) << " bytes" << std::endl;
    std::cout << "long long:\t" << sizeof(long long) << " bytes" << std::endl; // C++11, may not be supported by your compiler
    std::cout << "float:\t\t" << sizeof(float) << " bytes" << std::endl;
    std::cout << "double:\t\t" << sizeof(double) << " bytes" << std::endl;
    std::cout << "long double:\t" << sizeof(long double) << " bytes" << std::endl;

    int x;
    std::cout << "x is " << sizeof(x) << " bytes" << std::endl;

    //unsigned short y{65535};
    //unsigned short z{65537};

    //std::cout << "x is: " << y << std::endl;
    //std::cout << "y is: " << z << std::endl;


    int a{15};
    int b{7};
    double c; // Even though c is a double you lose fraction because a and b are int.
    c = a/b;
    std::cout << c;

    float f;
    f = 9.87654321f; // f suffix means this number should be treated as a float
    std::cout << f << std::endl;
    f = 987.654321f;
    std::cout << f << std::endl;
    f = 987654.321f;
    std::cout << f << std::endl;
    f = 9876543.21f;
    std::cout << f << std::endl;
    f = 0.0000987654321f;
    std::cout << f << std::endl;

    std::cout << std::setprecision(16);
    std::cout << f << std::endl;

    double d{1.0000};
    std::cout << std::setprecision(16);
    std::cout << d << std::endl;


    std::cout << true << std::endl;

    std::cout << std::boolalpha;

    std::cout << true << std::endl;

    std::cout << std::noboolalpha;

    std::cout << true << std::endl;

    return 0;

}
