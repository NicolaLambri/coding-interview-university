#include <iostream>
#include "list.cpp" // to avoid declaring usable class templates in list.cpp

int main () {
    SList<int> * l1 = new SList<int>; // initialize as new to call destructor
    std::cout << "Singly linked list size (l1): " << l1->Size () << std::endl;
    /*SList<int> * l2 = new SList<int>;
    std::cout << "Singly linked list size (l2): " << l2->Size () << std::endl;
    SList<int> * l3;
    l3 = &l1;
    std::cout << "Singly linked list size (l3): " << l3->Size () << std::endl;*/
    std::cout << "Empty list? " << l1->Empty () << std::endl;
    l1->Push_front (1);
    std::cout << "Value at 1: " << l1->Value_at (1) << std::endl;
    std::cout << "Pop front. Removed value: " << l1->Pop_front () << std::endl;
    l1->Push_front (10);
    l1->Push_front (7);
    std::cout << "Values at 1 and 2: " << l1->Value_at (1) << " " << l1->Value_at (2) << std::endl;
    l1->Push_back (4);
    std::cout << "Value pushed back: " << l1->Value_at (3) << std::endl;
    l1->Erase (1);
    l1->Print ();
    std::cout << "Value from end 1 and 2: " << l1->Value_from_end (1) << " " << l1->Value_from_end (2) << std::endl;
    std::cout << "Value from end outsize of bounds: " << l1->Value_from_end (10) << std::endl;
    l1->Push_back (12);
    l1->Push_back (5);
    l1->Push_back (78);
    l1->Push_back (100);
    l1->Insert(3, 34);
    l1->Insert(7, 1);
    std::cout << "SList: "; l1->Print ();
    l1->Reverse ();
    std::cout << "Reversed SList: "; l1->Print ();
    l1->Remove_value (78);
    l1->Print ();
    l1->Remove_value (10);
    l1->Print ();
    l1->Pop_back ();
    l1->~SList ();
}
