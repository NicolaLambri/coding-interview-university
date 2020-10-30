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
    // counting from 1
    if (head == nullptr) {
        std::cout << "Empty list." << std::endl;
        return -1;
    }
    if (position < 1 || position > size) {
        std::cout << "Position out of bounds." << std::endl;
        return -1;
    }
    SListNode<T> * pNode = head;
    // if position is 1 skip for loop
    for (int i = 1; i < position; ++i) {
        pNode = pNode->next;
    }
    return pNode->item;
}
template <class T>
void SList<T>::Push_front (SListNode<T>& node) {
    node.next = head; // make the new node point to the (old) first item of the list
    head = &node; // head now points to the new first item
    size++;
}
template <class T>
SList<T>& SList<T>::Push_front (const T& element) {
    SListNode<T> * pNode = new SListNode<T> (element);
    pNode->next = head;
    head = pNode;
    size++;
    return *this;
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
        // if empty list Push_back == Push_front
        this->Push_front (node);
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
SList<T>& SList<T>::Push_back (const T& element) {
    if (head == nullptr) return this->Push_front (element);
    SListNode<T> * pNode = new SListNode<T> (element);
    pNode->next = head;
    // continue until pNode points to the last node
    while (pNode->next->next != nullptr) {
        pNode->next = pNode->next->next; 
    }
    pNode->next->next = pNode;
    pNode->next = nullptr;
    size++;
    return *this;
}
template <class T>
T SList<T>::Pop_back () {
    if (head == nullptr) return -1;
    SListNode<T> * pNode = head; // pNode points to the first element of list
    // if list has only one element pop_back is equal to pop_front
    if (pNode->next == nullptr) return this->Pop_front ();
    while (pNode->next->next != nullptr) {
        // continue until the second-last element
        pNode = pNode->next;    
    }
    // save item to return
    T element = pNode->next->item;
    pNode->next = nullptr;
    size--;
    return element;
}
template <class T>
T SList<T>::Front () {
    if (head == nullptr) return -1;
    return head->item;
}
template <class T>
T SList<T>::Back () {
    if (head == nullptr) return -1;
    SListNode<T> * pNode = head; 
    while (pNode->next != nullptr) {
        pNode = pNode->next;
    }
    return pNode->item;
}
template <class T>
void SList<T>::Insert (const int& position, const T& element) {
    // index starts from 1 
    if (position == size) {
        this->Push_back (element);
        return;
    }
    if (position == 1) {
        this->Push_front (element);
        return;
    }
    if (position < 1 || position > size) { 
        std::cout << "Position out of bounds." << std::endl;
        return;
    }
    SListNode<T> * pNode = new SListNode<T> (element);
    pNode->next = head;
    for (int j = 2; j < position; ++j) {
        pNode = pNode->next;
    }
    // new node points to the next node
    pNode->next = pNode->next->next;
    // previous node points to the new node
    pNode->next->next = pNode; 
    size++;
}
template <class T>
void SList<T>::Erase (const int& position) {
    // position starts from 1
    if (this->Empty ()) {
        std::cout << "Empty list, nothing to erase." << std::endl;
        return;
    } 
    if (position < 0 || position > size) {
        std::cout << "Position out of bounds." << std::endl;
        return;
    }
    if (position == 1) {
        this->Pop_front ();
        return;
    }
    if (position == size) {
        this->Pop_back ();
        return;
    }
    SListNode<T> * pNode = head;
    for (int j = 2; j < position; ++j) {
        pNode = pNode->next;
    }
    pNode->next = pNode->next->next;
}
template <class T>
void SList<T>::Print () {
    for (SListNode<T> * pNode = head; pNode != nullptr; pNode = pNode->next) {
        std::cout << pNode->item << " ";
    }
    std::cout << std::endl;
}
template <class T>
T SList<T>::Value_from_end (const int& pos) {
    if (pos < 1 || pos > size) {
        std::cout << "Position out of bounds." << std::endl;
        return -1;
    }
    SListNode<T> * pNode = head;
    for (int j = 0; j < size - pos; ++j) {
        pNode = pNode->next;
    }
    return pNode->item;
}
template <class T>
void SList<T>::Reverse () {
    if (this->Empty()) {
        std::cout << "Empty list!" << std::endl;
        return;
    } 
    if (size == 1) return;
    // define poiter to node to reverse the list
    SListNode<T> * pNode;
    // save address of new head
    SListNode<T> * newhead;
    for (int i = 1; i < size; ++i) {
        pNode = head;
        // make pNode point to the second-last node
        while (pNode->next->next != nullptr) {
            pNode = pNode->next;
        }
        // update pointer of last node from nullptr to previous node
        pNode->next->next = pNode;
        // save address of new head
        if (i == 1) newhead = pNode->next;
        // second-last node points to nullptr
        pNode->next = nullptr;
    }
    head = newhead;
}
template <class T>
void SList<T>::Remove_value (const T& value) {
    if (this->Empty()) {
        std::cout << "Empty list." << std::endl;
        return;
    }
    // check if value is in the first node
    if (head->item == value) {
        head = head->next;
        return;
    }
    SListNode<T> * pNode = head;
    for (int j = 1; j < size; ++j) {
        if (pNode->next->item == value) {
            pNode->next = pNode->next->next;
            return;
        }
        pNode = pNode->next;
    }
}
