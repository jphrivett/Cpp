/*// Q2:
#include <algorithm> // for std::swap, use <utility> instead if C++11
#include <iostream>

int main()
{
    int array[] = { 30, 50, 20, 10, 40 };
    const int length = sizeof(array) / sizeof(array[0]);

    // Step through each element of the array except the last
    for (int startIndex = 0; startIndex < length - 1; ++startIndex)
    {
        // largestIndex is the index of the largest element we've encountered so far.
        int largestIndex = startIndex;

        // Search through every element starting at startIndex + 1
        for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
        {
            // If the current element is smaller than our previously found largest
            if (array[currentIndex] > array[largestIndex])
                // This is the new largest number for this iteration
                largestIndex = currentIndex;
        }

        // Swap our start element with our largest element
        std::swap(array[startIndex], array[largestIndex]);
    }

    // Now print our sorted array as proof it works
    for (int index = 0; index < length; ++index)
        std::cout << array[index] << ' ';

    return 0;
}*/

//Q3:
#include <utility>
#include <iostream>

int main()
{
    int array[] = { 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    const int length = sizeof(array) / sizeof(array[0]);

    int element = 0;
    int iteration = 0;
    bool swap = 0;

    for (; iteration < length - 1; ++iteration)
    {
        for(; element < length - iteration - 1; ++element)
        {
            if (array[element] > array[element + 1])
            {
                std::swap(array[element],array[element + 1]);
                swap = 1;
            }

        }

        if (swap == 0)
        {
            std::cout << "The array was sorted on iteration " << iteration + 1 << "\n";
            break;
        }

        element = 0;
        swap = 0;
    }

    for (int counter = 0; counter < length; ++counter)
        std::cout << array[counter] << " ";

    return 0;

}













