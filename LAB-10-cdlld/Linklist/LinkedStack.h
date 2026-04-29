#include "Node.h"
class LinkedStack {
    Node* top;
public:
    LinkedStack();
    ~LinkedStack();
    bool push(int val);
    bool pop(int &val);
};