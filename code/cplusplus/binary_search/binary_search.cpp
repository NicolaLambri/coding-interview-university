// Implement binary search on sorted array of integers
#include <iostream>
#include <cstdlib> // include cstdlib for random integral numbers
#include <algorithm> // include algorithm to sort array

int BinarySearch (const int array[], const int number, const int size)
{
    int min = 0;
    // Inside a function an array is treated as a pointer
    // so sizeof will return the size in byte occupied by the pointer
    int max = size;
    int position;
    while (max >= min)
    {
        position = (int) (max + min) / 2;
        if (array[position] == number)
        {
            return position; 
        }
        else if (array[position] < number)
        {
            min = position + 1;
        }
        else
        {
            max = position - 1;
        }
    }
    return -1;
}

int recursiveBinarySearch (const int array[], const int& number, const int& min, const int& max)
{
    if (max < min)
    {
        return -1;
    }
    int position = (int) (max + min) / 2;
    if (array[position] < number)
    {
        position = recursiveBinarySearch (array, number, position + 1, max);
    }
    else if (array[position] > number)
    {
        position = recursiveBinarySearch (array, number, min, position - 1);
    }
    else
    {
        return position;
    }
    return position;
}

int main ()
{
    int number, length, position;
    std::cout << "Insert size of array (search space): ";
    std::cin >> length;
    if (std::cin.fail())
    {
        std::cout << "Insert integral number.";
        return 0;
    }
    std::cout << std::endl;
    int * array = new int [length];
    std::cout << "[ ";
    for (int i = 0; i < length; ++i)
    {
        array[i] = i; // trivial example
        std::cout << array[i] << " ";
    }
    std::cout << "]" << std::endl;
    /*srand (time(NULL)); // initialize random seed
    for (int i = 0; i < length; ++i)
    {
        array[i] = rand() % (2 * length);
        // equivalent to *(array + i) = rand()
    }
    std::cout << "Before sort: [ ";
    for (int i = 0; i < length; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "]" << std::endl;
    std::sort (array, array + length); // sort the elements in range [first, last)
    std::cout << "After sort: [ ";
    for (int i = 0; i < length; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "]" << std::endl;
    // use sizeof just to show its utility
    int size = sizeof (array) / sizeof (array[0]);
    since array is a pointer sizeof (array) returns the size
    of the pointer not the total array size */
    std::cout << "Insert integral number to search: ";
    std::cin >> number;
    std::cout << std::endl;
    //position = BinarySearch (array, number, length);
    position = recursiveBinarySearch (array, number, 0, length);
    if (position == -1)
    {
        std::cout << "Number not found." << std::endl;
    }
    else
    {
        std::cout << "Found number at position: " << position << std::endl;
    }
    // return 0 implicit in main
}
