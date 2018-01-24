#include <iostream>

//Function prototypes:

//Better to make it a constant so the the function can't change it
//and use the changed version in the function (it won't effect the
//actual value though because a copy is made for the function
//parameter):
int sumTo(const int value);

//Better to use a reference for structures, because otherwise a copy
//of the structure is made for the function parameter and this is
//slow and unnecessary in this case:
void printEmployeeName(const Employee &employee);

//You should use Out to indicate that a parameter is an out parameter:
void minmax(const int a, const int b, int &minOut, int &maxOut);

//Should always use constant if the value is not to be changed by
//the function. This is important for pointers and references
//as the values can be changed by the function directly (they are not
//copies):
int getIndexOfLargestValue(const int *array, const int size);

//Use return by reference rather than return by pointer because
//question asks to return the array element (not a pointer or a copy
//of the array element):
const int* getElement(const int *array, const int index);

int main()
{
    return 0;
}
