#include <iostream>
#include "queue.h"

template <class T>
SListNode<T>::SListNode (const T& element) {
    item = element; 
    next = nullptr;
}

template <class T>
QueueSList<T>::QueueSList () {
    head = nullptr;
    tail = nullptr;
}
template <class T>
QueueSList<T>::~QueueSList () {
    SListNode<T> ** ppNode = &tail;
    while (*ppNode != nullptr) {
        tail = (*ppNode)->next;
        delete *ppNode;
        ppNode = &tail;
    }
    std::cout << "QueueSList deleted." << std::endl;
}
template <class T>
void QueueSList<T>::Enqueue (const T& element) {
    SListNode<T> * pNode = new SListNode<T> (element); 
    if (head == nullptr) head = pNode;
    pNode->next = tail;
    tail = pNode;
}
template <class T>
T QueueSList<T>::Dequeue () {
    try {
        if (head == nullptr) throw 1;
        SListNode<T> * pNode;
        pNode = head;
        T item = head->item;
        head = head->next;
        delete pNode;
        return item;

    } catch (int e) {
        std::cout << "Empty queue. Nothing to Dequeue." << std::endl;
        return 0;
    }
}
template <class T>
bool QueueSList<T>::Empty () {
    if (head == nullptr) return true;
    else return false;
}
template <class T>
void QueueSList<T>::Print () {
    SListNode<T> * pNode = tail;
    std::cout << "Items in queue: ";
    while (pNode != nullptr) {
        std::cout << pNode->item << " ";
        pNode = pNode->next;
    }
    std::cout << std::endl;
}

template <class T>
QueueArray<T>::QueueArray () : size(16), write(0), read(0){
    queue = new T [size]; 
}
template <class T>
QueueArray<T>::QueueArray (const int& len) : size(len), write(0), read(0){
    queue = new T [size]; 
}
template <class T>
void QueueArray<T>::Enqueue (const T& item) {
    if (this->Full()) {
        std::cout << "Queue is full, cannot allocate new item" << std::endl;
    }
    queue[write] = item;
    write = ++write % size; // mod size so that write cycles
}
template <class T>
T QueueArray<T>::Dequeue () {
    if (this->Empty()) std::cout << "Empty list, nothing to dequeue." << std::endl;
    T item = queue[read];
    read = ++read % size;
    return item;
}
template <class T>
bool QueueArray<T>::Empty () {
    if (write == read) return true;
    else return false;
}
template <class T>
bool QueueArray<T>::Full (){
    if (write + 1 == read) return true;
    else if (write == size - 1 && read == 0) return true;
    else return false;
}
