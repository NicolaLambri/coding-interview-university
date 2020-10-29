#include "list.h"
#include <iostream>

template <class T>
SListNode<T>::SListNode () : next(nullptr) {}
template <class T>
SListNode<T>::SListNode (const T& element, SListNode<T> * node) : item(element), next(node) {} // default pointer = nullptr

template <class T>
SList<T>::SList () : size(0), head(nullptr) {} // empty list
template <class T>
int SList<T>::Size () {
    return size;
}
template <class T>
bool SList<T>::Empty () {
    if (head == nullptr) return true;
    return false;
}
template <class T>
T SList<T>::Value_at (const int& position) {
    // counting from 0
    if (head == nullptr) {
        std::cout << "Empty list." << std::endl;
        return -1;
    } else if (position < 0 || position > size) {
        std::cout << "Position out of bounds." << std::endl;
        return -1;
    } else {
        SListNode<T> * node = head;
        // if position is 0 skip for loop
        for (int i = 0; i < position; ++i) {
            node = node->next;
        }
        return node->item;
    }
}
template <class T>
void SList<T>::Push_front (SListNode<T>& node) {
    node.next = head; // make the new node point to the (old) first item of the list
    head = &node; // head now points to the new first item
    size++;
}
template <class T>
T SList<T>::Pop_front () {
    if (head == nullptr) {
        std::cout << "Empty list." << std::endl;
        return -1;
    }
    T item = head->item; // assign removed item
    head = head->next; // redirect head
    size--;
    return item;
}
template <class T>
void SList<T>::Push_back (SListNode<T>& node) {
    if (head == nullptr) {
        head = &node;
        return;
    }
    SListNode<T> * pNode = head; // pNode points to the first element of list
    while (pNode->next != nullptr) {
        pNode = pNode->next;
    }
    pNode->next = &node;
    size++;
}
template <class T>
T SList<T>::Pop_back () {
    if (head == nullptr) {
        return -1;
    }
    SListNode<T> * pNode = head; // pNode points to the first element of list
    if (pNode->nullptr) {
    // if list has only one element pop_back is equal to pop_front
        this->Pop_front;
    }
    while (pNode->next->next != nullptr) {
        // continue until the second-last element
        pNode = pNode->next;    
    }
    pNode->next = nullptr;
    size--;
}
