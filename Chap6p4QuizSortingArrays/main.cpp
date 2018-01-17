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
}
