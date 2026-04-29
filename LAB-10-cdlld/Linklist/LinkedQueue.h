#include "Node.h"
class LinkedQueue
{
    Node* front;
    Node* back;
    public:
    LinkedQueue();
    bool enqueue(int val);
    bool dequeue(int& val);
    void display();
    ~LinkedQueue();
};