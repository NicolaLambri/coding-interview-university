#include <iostream>
#include "list.cpp" // to avoid declaring usable class templates in list.cpp

int main () {
    SList<int> l1;
    std::cout << "Singly linked list size (l1): " << l1.Size () << std::endl;
    /*SList<int> * l2 = new SList<int>;
    std::cout << "Singly linked list size (l2): " << l2->Size () << std::endl;
    SList<int> * l3;
    l3 = &l1;
    std::cout << "Singly linked list size (l3): " << l3->Size () << std::endl;*/
    std::cout << "Empty list? " << l1.Empty () << std::endl;
    SListNode<int> node1 = (1);
    l1.Push_front (node1);
    std::cout << "Value at 0: " << l1.Value_at(0) << std::endl;
    std::cout << "Pop front. Removed value: " << l1.Pop_front () << std::endl;
}
