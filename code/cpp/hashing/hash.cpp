#include <iostream>
#include <iterator>
#include "hash.h"

template <class K, class I>
HashNode<K,I>::HashNode (const K& k, const I& i) : key(k), item(i) {}; 

template <class K, class I>
int HashTable<K,I>::hash (const K& key, const int& i, const int& cap) {
    return (key + i) % cap; // linear probing with bad hash function
}
template <class K, class I>
void HashTable<K,I>::resize (const int& new_cap) {
    std::cout << "Resize table to " << new_cap << std::endl;
    HashNode<K,I> ** newtable = new HashNode<K,I> * [new_cap];
    for (int i = 0; i < new_cap; ++i) {
        newtable[i] = nullptr; // initialize new table
    }
    for (int i = 0; i < capacity; ++i) {
        if (table[i] != nullptr) {
            if (table[i] == deleted)
                continue;
            int j = 0;
            int node = hash (table[i]->key, j, new_cap);
            while (newtable[node] != nullptr) {
                j++;
                node = hash (table[i]->key, j, new_cap);
            }
            newtable[node] = table[i];
        }
    }
    delete[] table;
    capacity = new_cap;
    table = newtable;
}
template <class K, class I>
HashTable<K,I>::HashTable () : size(0), capacity(16){
    table = new HashNode<K,I> * [capacity];
    for (int i = 0; i < capacity; ++i) {
        table[i] = nullptr;
    }
    deleted = new HashNode<K,I> (-1, -1);
}
template <class K, class I>
HashTable<K,I>::HashTable (const int& m) : size(0), capacity(m) {
    table = new HashNode<K,I> * [capacity];
    for (int i = 0; i < capacity; ++i) {
        table[i] = nullptr;
    }
    deleted = new HashNode<K,I> (-1, -1);
}
template <class K, class I>
HashTable<K,I>::~HashTable () {
    for (int i = 0; i < capacity; ++i) {
        delete table[i];
    }
    delete[] table;
}
template <class K, class I>
void HashTable<K,I>::add (const K& key, const I& item) {
    if (size == capacity)
        this->resize (2 * capacity);
    int i = 0;
    int node = hash (key, i, capacity); 
    while (table[node] != nullptr) {
        if (table[node]->key == key) {
            table[node]->item = item; // same key -> overwrite item
            size++;
            return;
        }
        i++;
        node = hash (key, i, capacity);
    }
    table[node] = new HashNode<K,I> (key, item); // insert new node
    size++;
}
template <class K, class I>
void HashTable<K,I>::remove (const K& key) {
    if (size == capacity / 4)
        this->resize (capacity / 2);
    int i = 0;
    int node = hash (key, 0, capacity);
    while (table[node]->key != key) {
        i++;
        node = hash (key, i, capacity);
        if (table[node] == nullptr || i == capacity) {
            std::cout << "Key not stored. Cannot delete it." << std::endl;
            return;
        }
    }
    delete table[node];
    table[node] = deleted;
    size--;
}
template <class K, class I>
I HashTable<K,I>::get (const K& key) {
    int i = 0;
    int node = hash (key, 0, capacity);
    while (table[node]->key != key) {
        i++;
        node = hash (key, i, capacity);
        if (table[node] == nullptr || i == capacity) {
            std::cout << "Key not in table." << std::endl;
        }
    }
    return table[node]->item;
}
template <class K, class I>
bool HashTable<K,I>::exists (const K& key) {
    int i = 0;
    int node = hash (key, 0, capacity);
    while (table[node]->key != key) {
        i++;
        node = hash (key, i, capacity);
        if (table[node] == nullptr || i == capacity) {
            return false;
        }
    }
    return true;
}
