#include <iostream>
#include "hash.cpp"

int main () {
    HashTable<int, int> * ht = new HashTable<int, int> (4);
    ht->add (14, 105); 
    ht->add (100, 1);
    ht->add (12, 124);
    ht->add (81, 56);
    ht->add (32, 0);
    std::cout << "Get item with key 12: " << ht->get (12) << std::endl;
    std::cout << "Exists item with key 1? " << ht->exists (1) << " And key 32? " << ht->exists (32) << std::endl;
    for (int i = 0; i < 32; ++i) {
        ht->add (i, i);
    }
    for (int i = 0; i < 22; ++i) {
        ht->remove (i);
    }
}
