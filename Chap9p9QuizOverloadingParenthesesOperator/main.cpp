#include <iostream>
#include <string>

class String
{
private:
    std::string m_string;

public:
    String(const std::string myString = "") : m_string{myString}
    {

    }

    std::string operator()(int idx, int length);

};

std::string String::operator()(int idx, int length)
{
    std::string tempString {""};

    for (int i = idx; i < idx + length; ++i)
        tempString += m_string[i];

    return tempString;
}

int main()
{
    String string("Hello, world!");
    std::cout << string(7, 5); // start at index 7 and return 5 characters

    return 0;
}
