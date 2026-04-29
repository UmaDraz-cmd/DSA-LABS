#pragma once
#include "Node.h"
class LinkedList {
    Node* head;
    int findMin(Node* head);
    int countEven(Node* head);
public:
    LinkedList();
    void unSortedInsert(int val);
    void SortedInsert(int val);
    bool unSortedRemove(int val);
    bool sortedRemove(int val);
    void display();
    int findMax();
    bool search(int key);
    void displayReverse();
    ~LinkedList();
    LinkedList(const LinkedList& other);
    LinkedList& operator=(const LinkedList& other);
    int findMin();
    int countEvens ();
    void splitlinklist(LinkedList& l1,LinkedList& l2);
};