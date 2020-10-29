#include "vector.h"
#include <cmath>
#include <iostream>

template <class T>
Vector<T>::Vector (const int cap) : size(0) {
    // capacity = power of 2
    capacity = pow(2, round(log2(cap)));
    vec = new T [capacity]; // dinamic memory allocation    
}
template <class T>
Vector<T>::Vector () : capacity(16), size(0) {
    // default capacity 16
    vec = new T [capacity];
}
template <class T>
Vector<T>::~Vector () {
    delete[] vec;
}
template <class T>
int Vector<T>::Size () {
    return size;
}
template <class T>
int Vector<T>::Capacity () {
    return capacity;
}
template <class T>
bool Vector<T>::is_empty () {
    if (size == 0) {
        return true;
    }
    return false;
}
template <class T>
int Vector<T>::at (const int index) {
    return *(vec + index);
    // equivalent to vec[index]
}
template <class T>
void Vector<T>::push (const T value) {
    if (size == capacity) {
        resize (2 * capacity);
    }
    vec[size++] = value;
}
template <class T>
void Vector<T>::resize (const int new_cap) {
    T * new_vec = new T [new_cap]; // resize array 
    for (int i = 0; i < capacity; ++i) {
        new_vec [i] = vec[i];
    }
    delete[] vec; // free array of memory pointed by vec
    vec = new_vec;
    capacity = new_cap;
}
template <class T>
void Vector<T>::insert (const int i, const T value) {
    if (i < 0 || i > size - 1) {
        return;
    }
    if (size == capacity) {
        resize (2 * capacity) ;
    }
    for (int j = size; j > i; --j) {
        vec[j] = vec[j - 1];
    }
    vec[i] = value;
    size++;
}
template <class T>
void Vector<T>::prepend (const T value) {
    insert (0, value);
}
template <class T>
T Vector<T>::pop () {
    // can't delete single element of an array
    T value = vec[--size];
    if (size == (int) capacity / 4) {
        resize ((int) capacity / 2);    
    }
    return value;
}
template <class T>
void Vector<T>::del (const int i) {
    if (i < 0 || i > size - 1) {
        return;
    }
    for (int j = i; j < size - 1; ++j) {
        vec[j] = vec[j + 1];
    }
    size--;
    if (size == (int) capacity / 4) {
        resize ((int) capacity / 2);    
    }
}
template <class T>
void Vector<T>::remove (const T value) {
    // look for value and remove it (even in multiple places)
    for (int i = 0; i < size; ++i) {
        if (vec[i] == value) {
            del (i);
        }
    }    
}
template <class T>
int Vector<T>::find (const T value) {
    // look for value and return first index with that value (return -1 if not present)
    for (int i = 0; i < size; ++i) {
        if (vec[i] == value) {
            return i;
        }
    }
    return -1;
}
template <class T>
void Vector<T>::printVec () {
    std::cout << "[ ";
    for (int i = 0; i < size; ++i) {
        // just to use pointers
        std::cout << *(vec + i);
        if (i != size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

// Vector can only be used with int or double
template class Vector<int>;
template class Vector<double>;
