#include <string>

#pragma once

template <class K, class I>
class HashNode {
    public:
    K key;
    I item;
    HashNode (const K&, const I&);
};

template <class K, class I>
class HashTable {
    int size; // current size of the table
    int capacity; // capacity of the table
    HashNode<K,I> ** table; // table as array of pointers to use nullptr
    HashNode<K,I> * deleted; // pointer to a dummy hash node to separate an empty node from a deleted one
    int hash (const K&, const int&, const int&);
    void resize (const int&);
    public:
    HashTable ();
    HashTable (const int&);
    ~HashTable ();
    void add (const K&, const I&);
    void remove (const K&);
    I get (const K&);
    bool exists (const K&);
};
