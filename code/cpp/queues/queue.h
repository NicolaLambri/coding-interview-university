#pragma once

template <class T>
class SListNode {
    public:
    T item;
    SListNode<T> * next;
    SListNode (const T&);
};

template <class T>
class QueueSList {
    SListNode<T> * head, * tail;
    public:
    QueueSList ();
    ~QueueSList ();
    void Enqueue (const T&);
    T Dequeue ();
    bool Empty ();
    void Print ();
};

template <class T>
class QueueArray {
    T * queue;
    int size, write, read;
    public:
    QueueArray ();
    QueueArray (const int&);
    void Enqueue (const T&);
    T Dequeue ();
    bool Empty ();
    bool Full ();
};
