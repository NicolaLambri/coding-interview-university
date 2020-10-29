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
    int Size ();
    bool Empty ();
    T Value_at (const int&);
    void Push_front (SListNode<T>&);
    T Pop_front ();
    void Push_back (SListNode<T>&);
    T Pop_back ();
};
