#pragma once
class Node {
    friend class LinkedList;
    friend class LinkedStack;
    friend class LinkedQueue;
    int data;
    Node* next;
public:
    Node();
};