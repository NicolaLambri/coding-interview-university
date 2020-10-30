#include <iostream>
#pragma once

// single node class
template <class T>
class SListNode {
    public:
    T item;
    SListNode<T> * next; // recursive data type, next points to the next node
    SListNode ();
    SListNode (const T&, SListNode<T> * node = nullptr);
};

// manage singly linked list
template <class T>
class SList {
    int size;
    SListNode<T> * head; // head of the list
    public:
    SList ();
    ~SList ();
    int Size ();
    bool Empty ();
    T Value_at (const int&);
    void Push_front (SListNode<T>&);
    // overload to insert new node using only item
    SList<T>& Push_front (const T&);
    T Pop_front ();
    void Push_back (SListNode<T>&);
    SList<T>& Push_back (const T&);
    T Pop_back ();
    T Front ();
    T Back ();
    void Insert (const int&, const T&);
    void Erase (const int&);
    void Print ();
    T Value_from_end (const int&);
    void Reverse ();
    void Remove_value (const T&);
};
