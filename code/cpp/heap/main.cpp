#include <iostream>
#include <vector>

template <class T>
void swap (T& a, T& b) {
    T temp = a; a = b; b = temp;
}

template <class T>
void sift_up (std::vector<T>& v) {
    // v[0] = heap_size
    for (unsigned i = v[0]; i > 1 && v[i] > v[i / 2] ; i /= 2)
        swap (v[i], v[i / 2]);
}

template <class T>
void insert (std::vector<T>& v, T& key) {
    v.push_back (key); 
    v[0]++;
    sift_up (v);
}

// max, size and empty functions are pretty useless
// with this direct implementation of heap in main
template <class T>
T max (std::vector<T>& v) {
    return v[1];
}
template <class T>
int size (std::vector<T>& v) {
    return v[0];
}
template <class T>
bool empty (std::vector<T>& v) {
    return (v[0] == 0) ? true : false;
    //return (v.size () == 1) ? true : false;
}

unsigned index_max (int& a, int& b, unsigned& i) {
    return (a > b) ? 2*i : 2*i + 1;
}

template <class T>
void sift_down (std::vector<T>& v, unsigned i) {
    // stop at the second-last level (height 1)
    // which means consider the first half of the vector
    while (i <= v[0] / 2) {
        // as the heap is a nearly complete binary tree
        // we need to check if the last parent has only one child (the left one)
        // which happens only if heap_size is even
        if (i == v[0] / 2 && v[0] % 2 == 0) { 
            // check if we need to swap parent's and child's keys
            if (v[i] < v[2*i]) {
                swap (v[i], v[2*i]);
                i *= 2;
            }
            else break;
        }
        // if both children are greater than parent we swap
        // parent and the maximum children
        else if (v[i] < v[2*i] && v[i] < v[2*i + 1]) {
            unsigned idm = index_max (v[2*i], v[2*i + 1], i);
            swap (v[i], v[idm]);
            i = idm;
        }
        else if (v[i] < v[2*i]) {
            swap (v[i], v[2*i]);
            i *= 2;
        }
        else if (v[i] < v[2*i + 1]) {
            swap (v[i], v[2*i + 1]);
            i = 2*i + 1;
        }
        else break;
    }
}

template <class T>
T extract_max (std::vector<T>& v) {
    T max = v[1];
    v[1] = v.back (); v.pop_back(); v[0]--;
    sift_down (v, 1);
    return max;
}

template <class T>
void remove (std::vector<T>& v, T& key) {
    int i = 0;
    for (auto it = v.begin (); it != v.end (); ++it, ++i) {
        if (*it == key) {
            *it = v.back ();
            v.pop_back (); v[0]--;
            std::cout << "Key removed." << std::endl;
            sift_down (v, i);
            return;
        }
    }
    std::cout << "Key not found. Nothing to remove." << std::endl;
}

template <class T>
void build_max_heap (std::vector<T>& v) {
    for (unsigned i = v[0] / 2; i > 0; --i)
        sift_down (v, i);
}

template <class T>
void heapsort (std::vector<T>& v) {
    build_max_heap (v); // O(n)
    while (!empty(v)) { // O(n logn)
        swap (v[1], v[v[0]]); // v[0] = heap_size
        v[0]--; // decrement heap_size
        sift_down (v, 1); // O(logn)
    }
}

template <class T>
void print (std::vector<T>& v) {
    // auto will set it to std::vector::iterator
    for (auto it = v.begin () + 1; it != v.end (); ++it)
        std::cout << *it << " "; 
    std::cout << std::endl;
}

int main () {
    // first element of array set zero so that
    // heap indexing begins at 1
    /*std::vector<int> heap (1, 0);
    std::cout << "Populate the heap with insert. This is slow ~O(nlogn)." << std::endl;
    for (unsigned i = 0; i < 13; ++i) {
        int key;
        std::cout << "Insert key: "; std::cin >> key;
        insert (heap, key);
    }
    print (heap);
    std::cout << "Extract max... " << extract_max (heap) << std::endl;
    print (heap);
    int value;
    std::cout << "Insert key to remove: "; std::cin >> value; remove (heap, value);
    print (heap);*/
    // first element of array keeps heap size
    // so that heap indexing begins at 1
    std::vector<int> heap2 (1, 0);
    std::cout << "Populate the heap with build_max_heap. This is efficient ~O(n)." << std::endl;
    for (unsigned i = 0; i < 10; ++i) {
        int key;
        std::cout << "Insert key: "; std::cin >> key;
        heap2.push_back (key);
        heap2[0]++;
    }
    std::cout << "Unordered array: "; print (heap2);
    build_max_heap (heap2);
    std::cout << "Max-heap: "; print (heap2);
    heapsort (heap2); print (heap2);
}
