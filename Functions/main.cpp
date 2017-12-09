#include <iostream>

using namespace std;

int anotherFunction()
{
    cout << "Enter a number: ";
    int x;
    cin >> x;
    return x;
}

int main()
{
    int a = anotherFunction();
    int b = anotherFunction();

    cout << "The sum is: " << a + b;
    //cout << "Start main()" << endl;
    //anotherFunction();
    //cout << "main() after anotherFunction()" << endl;

    //cout << anotherFunction() << endl;

    return 0;
}
