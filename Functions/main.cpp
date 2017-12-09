#include <iostream>

using namespace std;

int doubleNumber(int a)
{
    return a + a;
}

int main()
{
    int x;
    cin >> x;
    cout << doubleNumber(x);
    return 0;
}
