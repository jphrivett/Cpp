#include <iostream>

using namespace std;

int anotherFunction()
{
    cout << "Calls anotherFunction()" << endl;
    return 5;
}

int main()
{
    cout << "Start main()" << endl;
    anotherFunction();
    cout << "main() after anotherFunction()" << endl;

    cout << anotherFunction() << endl;

    return 0;
}
