#include <iostream>
#include "vector.h"

int main ()
{
    Vector<int> vec (3);
    std::cout << "Vector capacity: " << vec.Capacity () << std::endl;
    vec.push (4);
    vec.push (1);
    vec.push (5);
    vec.push (10);
    vec.insert (2, 1);
    std::cout << "Popped value: " << vec.pop () << std::endl;
    std::cout << "Vector size: " << vec.Size () << std::endl;
    vec.del (3);
    std::cout << "Vector size after deleting one element: " << vec.Size () << std::endl;
}
