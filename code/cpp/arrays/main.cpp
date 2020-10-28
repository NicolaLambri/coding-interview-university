#include <iostream>
#include "vector.h"

int main ()
{
    Vector<int> vec1;
    std::cout << "Vector1 default capacity: " << vec1.Capacity() << std::endl;
    //Vector<double> vec2 (10);
    //std::cout << "Vector2 capacity: " << vec2.Capacity() << std::endl;
}
