#pragma once // does the same thing as ifndef block
// #ifndef _vector_h_
// #define _vector_h_

template <class T>
class Vector {
    int size, capacity;
    T * vec; // vec is a pointer to int
    void resize (const int); // resize if size=capacity in push, or size=capacity/4 in pop
    public:
    Vector<T> (const int);
    Vector<T> ();
    ~Vector<T> ();
    int Size ();
    int Capacity ();
    bool is_empty ();
    int at (const int);
    void push (const T);
    void insert (const int, const T);
    void prepend (const T);
    T pop ();
    void del (const int);
    void remove (const T);
    int find (const T);
};

// #endif
