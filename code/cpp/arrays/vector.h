#pragma once // does the same thing as ifndef block
// #ifndef _vector_h_
// #define _vector_h_

template <class T>
class Vector
{
    int size, capacity;
    T * vec; // vec is a pointer to int
    public:
    Vector<T> (const int);
    Vector<T> ();
    ~Vector<T> ();
    int Size ();
    int Capacity ();
    bool is_empty ();
    int at (const int);
};

// #endif
