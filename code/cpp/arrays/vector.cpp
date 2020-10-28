#include "vector.h"

template <class T>
Vector<T>::Vector (const int cap) : capacity(cap)
{
    vec = new T [capacity]; // dinamic memory allocation    
}
template <class T>
Vector<T>::Vector () : capacity(16), size(0)
{
    vec = new T [capacity];
}
template <class T>
Vector<T>::~Vector ()
{
    delete[] vec;
}
template <class T>
int Vector<T>::Size ()
{
    return size;
}
template <class T>
int Vector<T>::Capacity ()
{
    return capacity;
}
template <class T>
bool Vector<T>::is_empty ()
{
    if (size == 0)
    {
        return true;
    }
    else
    {
    return false;
    }
}
template <class T>
int Vector<T>::at (const int index)
{
    return *(vec + index);
}

// Vector can only be used with int or double
template class Vector<int>;
template class Vector<double>;
