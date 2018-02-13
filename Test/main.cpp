#include "testHeader1.h"
#include "testHeader2.h"


int main()
{
    Storage storage(5, 6.7);
    Display display(false);

    display.displayItem(storage);

    return 0;
}
