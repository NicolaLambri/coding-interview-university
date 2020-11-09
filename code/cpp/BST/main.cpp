#include <iostream>
#include <queue> // breadth-first print

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
    std::cout << pNode->value << " ";
    print (pNode->right);
}

// Breadth-first print
template <class T>
void bf_print (BstNode<T> * const &pNode) {
    if (pNode == nullptr) {
        std::cout << "Empty tree." << std::endl;
        return;
    }
    std::queue<BstNode<T> *> Q;
    Q.push(pNode);
    while (!Q.empty()){
        if (Q.front()->left != nullptr)
            Q.push(Q.front()->left); // enqueue left child
        if (Q.front()->right != nullptr)
            Q.push(Q.front()->right); // enqueue right child
        std::cout << Q.front()->value << " ";
        Q.pop(); // remove parent node
    }
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

int max (int &a, int &b) {
    return a >= b ? a : b;
}

template <class T>
int height (BstNode<T> * &pNode) { // O(n) we have to visit each node
    if (pNode == nullptr)
        return -1; // leaves' height is zero 
    int hleft = 0, hright = 0;
    hleft += height (pNode->left);
    hright += height (pNode->right);
    return max (hleft, hright) + 1;
    // even more compact:
    // return max (height (pNode->left), height(pNode->right)) + 1;
}

// iterative implementation
template <class T>
T get_min (BstNode<T> * pNode) {
    if (pNode == nullptr)
        return -1;
    while (pNode->left != nullptr)
        pNode = pNode->left;
    return pNode->value;
}
/* recursive implementation
template <class T>
T get_min (BstNode<T> * &pNode) {
    if (pNode == nullptr)
        return -1;
    else if (pNode->left == nullptr)
        return pNode->value;
    // search in left subtree
    return get_min (pNode->left); 
}
*/

template <class T>
T get_max (BstNode<T> * pNode) {
    if (pNode == nullptr)
        return -1;
    while (pNode->right != nullptr)
        pNode = pNode->right;
    return pNode->value;
}

// check whether tree is a BST
template <class T>
bool is_Bst (BstNode<T> * &pNode) {
    bool check_bst = true;
    if (pNode->left != nullptr) {
        // check left subtree
        check_bst = is_Bst (pNode->left);
        if (pNode->value < pNode->left->value)
            check_bst = false;
    }
    // if tree is not a BST that continue to return
    if (check_bst == false)
        return check_bst;
    if (pNode->right != nullptr) {
        // check right subtree (in case left subtree is a BST)
        check_bst = is_Bst (pNode->right);
        if (pNode->value >= pNode->right->value)
            check_bst = false;
    }
    return check_bst;
}

template <class T>
void delete_key (BstNode<T> * &pNode, T &v) {
    if (pNode == nullptr) {
        std::cout << "Value not in tree." << std::endl;
        return;
    }
    if (v < pNode->value)
        delete_key (pNode->left, v);
    else if (v > pNode->value)
        delete_key (pNode->right, v);
    else {
        if (pNode->left == nullptr && pNode->right == nullptr) {
            delete pNode; // delete leaf
            pNode = nullptr;
            std::cout << "Value deleted" << std::endl;
        }
        else if (pNode->left == nullptr) {
            // node has a single child on the right
            BstNode<T> * child = pNode->right;
            delete pNode;
            std::cout << "Value deleted" << std::endl;
            pNode = child;
        }
        else if (pNode->right == nullptr) {
            // node has a single child on the left
            BstNode<T> * child = pNode->left;
            delete pNode;
            std::cout << "Value deleted" << std::endl;
            pNode = child;
        }
        else {
            // node has two children 
            BstNode<T> * childr = pNode->right;
            BstNode<T> * childl = pNode->left;
            delete pNode;
            std::cout << "Value deleted" << std::endl;
            pNode = childr;
            while (childr->left != nullptr)
                childr = childr->left;
            // make the leftmost leaf of the right subtree of pNode (childr)
            // point to the root of the left child of pNode
            childr->left = childl;
        }
            
    }
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
    print (root); std::cout << std::endl;
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
    std::cout << "Is it a BST? " << is_Bst (root) << std::endl;
    std::cout << "Tree's height: " << height (root) << std::endl;
    std::cout << "Insert value to delete: "; std::cin >> value;
    delete_key (root, value);
    std::cout << "Is it still a binary tree? " << is_Bst (root) << std::endl;
    print (root); std::cout << std::endl;
    std::cout << "Breadth-first print: "; bf_print (root); std::cout << std::endl;
    delete_tree (root);
    std::cout << "Tree deleted." << std::endl;
}
