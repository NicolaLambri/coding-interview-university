#include <iostream>

template <class T>
struct BstNode {
    T value;
    BstNode * left, * right;
};

template <class T>
BstNode<T> * GetNewNode (const T& v) {
    BstNode<T> * pNode = new BstNode<T>;
    pNode->value = v;
    pNode->left = nullptr;
    pNode->right = nullptr;
    return pNode;
}

template <class T>
void insert (BstNode<T> *& pNode, const T &v) {
    if (pNode == nullptr)
        pNode = GetNewNode (v);
    else if (v < pNode->value)
        insert (pNode->left, v);
    else 
        insert (pNode->right, v);
    return;
}

template <class T>
int count_nodes (BstNode<T> * const &pNode) {
    int count = 1;
    if (pNode == nullptr)
        return 0;
    count += count_nodes (pNode->left);
    count += count_nodes (pNode->right);
    return count;
}

// print values from min to max
template <class T>
void print (BstNode<T> * const &pNode) {
    if (pNode == nullptr)
        return;
    print (pNode->left);
    std::cout << pNode->value << " " << std::endl;
    print (pNode->right);
}

template <class T>
void delete_tree (BstNode<T> * &pNode) {
    if (pNode == nullptr)
        return;
    delete_tree (pNode->left);
    delete_tree (pNode->right);
    delete pNode;
}

template <class T>
bool is_in_tree (BstNode<T> * const &pNode, const T &v) {
    if (pNode == nullptr)
        return false;
    else if (v < pNode->value)
        return is_in_tree (pNode->left, v);
    else if (v > pNode->value)
        return is_in_tree (pNode->right, v);
    return true;
        
}

template <class T>
T get_min (BstNode<T> * pNode) {
    while (pNode->left != nullptr)
        pNode = pNode->left;
    return pNode->value;
}

template <class T>
T get_max (BstNode<T> * pNode) {
    while (pNode->right != nullptr)
        pNode = pNode->right;
    return pNode->value;
}

// return the next-highest value in tree after given value
template <class T>
T next_highest (BstNode<T> * pNode, T &v) {
    T nexth;
    while (pNode != nullptr) { // O(h)
        if (v == pNode->value)
            return v; // key = value
        else if (v < pNode->value) {
            nexth = pNode->value; // update nexth
            pNode = pNode->left; // then go left
        }
        else {
            pNode = pNode->right; // first move right
            // we need the second condition to keep track of nexth
            // if we go left then right
            if (pNode != nullptr && pNode->value > nexth)
                // then update nexth if nexth is smaller than next node's key
                nexth = pNode->value;
        }
    }
    if (v > nexth)
        return -1; // value is greater than any key
    else
        return nexth;
}

int main () {
    BstNode<int> * root = nullptr;
    int value;
    std::cout << "Number of nodes: " << count_nodes (root) << std::endl;
    // a recursive insert force to pass
    // BstNode * root as argument
    insert (root, 50); insert (root, 34); insert (root, 61);
    insert (root, 10); insert (root, 38); insert (root, 4);
    insert (root, 22); insert (root, 55); insert (root, 96);
    insert (root, 46); insert (root, 78);
    print (root);
    std::cout << "Number of nodes: " << count_nodes (root) << std::endl;
    std::cout << "Insert value to search: "; std::cin >> value;
    if (is_in_tree (root, value) == true)
        std::cout << "Found." << std::endl;
    else
        std::cout << "Not found." << std::endl;
    std::cout << "Min value in the tree: " << get_min (root) << std::endl;
    std::cout << "Max value in the tree: " << get_max (root) << std::endl;
    std::cout << "Insert value: "; std::cin >> value;
    std::cout << "Next-highest to the value in the tree is: " << next_highest (root, value) << std::endl;
    delete_tree (root);
    std::cout << "Tree deleted." << std::endl;
}
