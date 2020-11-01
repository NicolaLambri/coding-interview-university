#include <iostream>
#include "queue.cpp"

int main () {
    QueueSList<int> * q1 = new QueueSList<int> ();
    std::cout << "Is queue empty? " << q1->Empty () << std::endl;
    q1->Enqueue (2); q1->Enqueue (5); q1->Enqueue (6); 
    q1->Print ();
    int dequeued  = q1->Dequeue ();
    std::cout << "Dequeued element: " << dequeued << std::endl;
    dequeued  = q1->Dequeue ();
    std::cout << "Dequeued element: " << dequeued << std::endl;
    dequeued  = q1->Dequeue ();
    std::cout << "Dequeued element: " << dequeued << std::endl;
    dequeued  = q1->Dequeue ();
    std::cout << "Dequeued element: " << dequeued << std::endl;
    q1->~QueueSList ();
    QueueArray<int> q2 (3);
    q2.Enqueue (1);
    q2.Enqueue (2);
    std::cout << "Queue full? " << q2.Full () << std::endl;
    q2.Enqueue(3);
}
