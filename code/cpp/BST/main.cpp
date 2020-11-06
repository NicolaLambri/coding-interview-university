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
void insert (BstNode<T> *& pNode, const T& v) {
    if (pNode == nullptr)
        pNode = GetNewNode (v);
    else if (v < pNode->value)
        insert (pNode->left, v);
    else 
        insert (pNode->right, v);
    return;
}

template <class T>
int count_nodes (BstNode<T> *& pNode) {
    int count = 1;
    if (pNode == nullptr)
        return 0;
    count += count_nodes (pNode->left);
    count += count_nodes (pNode->right);
    return count;
}

// print values from min to max
template <class T>
void print (BstNode<T> *& pNode) {
    if (pNode == nullptr)
        return;
    print (pNode->left);
    std::cout << pNode->value << " " << std::endl;
    print (pNode->right);
}

template <class T>
void delete_tree (BstNode<T> *& pNode) {
    if (pNode == nullptr)
        return;
    delete_tree (pNode->left);
    delete_tree (pNode->right);
    delete pNode;
}

template <class T>
bool is_in_tree (BstNode<T> *& pNode, const T& v) {
    if (pNode == nullptr)
        return false;
    else if (v < pNode->value)
        return is_in_tree (pNode->left, v);
    else if (v > pNode->value)
        return is_in_tree (pNode->right, v);
    return true;
        
}

int main () {
    BstNode<int> * root = nullptr;
    std::cout << "Number of nodes: " << count_nodes (root) << std::endl;
    // a recursive insert force to pass
    // BstNode * root as argument
    insert (root, 10);
    insert (root, 15);
    insert (root, 4);
    insert (root, 22);
    insert (root, 14);
    insert (root, 96);
    insert (root, 46);
    insert (root, 78);
    print (root);
    std::cout << "Number of nodes: " << count_nodes (root) << std::endl;
    std::cout << "Is 46 in BST? " << is_in_tree (root, 46) << std::endl;
    delete_tree (root);
    std::cout << "Tree deleted." << std::endl;
}
