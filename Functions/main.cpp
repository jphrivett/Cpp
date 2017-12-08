#include <iostream>

using namespace std;

void anotherFunction()
{
    cout << "Calls anotherFunction()" << endl;
}

int main()
{
    cout << "Start main()" << endl;
    anotherFunction();
    cout << "main() after anotherFunction()" << endl;


    return 0;
}
