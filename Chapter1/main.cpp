#include "io.h"

int main()
{
    int int1{readNumber()};
    int int2{readNumber()};

    int summedInts{int1 + int2};

    writeAnswer(summedInts);
    return 0;

}


