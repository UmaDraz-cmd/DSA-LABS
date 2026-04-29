#include "LinkedStack.h"

LinkedStack::LinkedStack() {
    top = nullptr;
}

LinkedStack::~LinkedStack() {
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

bool LinkedStack::push(int val) {
    if (top == nullptr) {
        top = new Node;
        top->data = val;
    } else {
        Node* temp = new Node;
        temp->data = val;
        temp->next = top;
        top = temp;
    }
    return true;
}

bool LinkedStack::pop(int &val) {
    if (top == nullptr) {
        return false;
    } else {
        Node* temp = top;
        top = top->next;
        val = temp->data;
        delete temp;
        return true;
    }
}