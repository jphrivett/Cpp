#include <iostream>

double getDouble()
{
    std::cout << "Enter a double value: \n";
    double x;
    std::cin >> x;
    return x;
}

char getSym()
{
    std::cout << "Enter either +, -, * or /: ";
    char x;
    std::cin >> x;
    return x;
}

bool isSymbolAllowed(char sym)
{
    bool x{false};

    if (sym == '+')
        x = true;
    else if (sym == '-')
        x = true;
    else if (sym == '*')
        x = true;
    else if (sym == '/')
        x = true;
    else
        x = false;

    return x;
}


double doCalculation(double db1, double db2, char sym)
{
    double ans = 0.0;

    if (sym == '+')
        ans = db1 + db2;
    else if (sym == '-')
        ans = db1 - db2;
    else if (sym == '*')
        ans = db1 * db2;
    else if (sym == '/')
        ans = db1 / db2;

    return ans;
}

void printAns(double ans)
{
    std::cout << "The answer is: " << ans << "\n";
}

int main()
{
    double db1 = getDouble();
    double db2 = getDouble();
    char sym = getSym();

    // Could have put this all into a single function as in
    // Chapter 2 comprehensive quiz:
    // http://www.learncpp.com/cpp-tutorial/210-comprehensive-quiz/
    bool check = isSymbolAllowed(sym);

    if (check)
    {
        double ans = doCalculation(db1, db2, sym);
        printAns(ans);
    }
    else
        std::cout << "You did not enter a valid symbol.";
    // Until here.

    return 0;
}
