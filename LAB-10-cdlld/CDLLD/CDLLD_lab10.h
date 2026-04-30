#pragma once
class DNode
{
    friend class CDLLD;
    int data;
    DNode* next;
    DNode* prev;
    
};
class CDLLD
{
private:
    DNode head;
public:
    CDLLD();
    ~CDLLD();
    bool insertAtStart(int val);
    bool insertAtEnd(int val);
    CDLLD(const CDLLD& other);
    bool sortedInsert(int val);
    bool sortedRemove(int val);
    bool unsortedRemove(int val);
    void combine(CDLLD &list1, CDLLD &list2);
    void shuffleMerge (CDLLD& list1, CDLLD& list2);
    void splitList (CDLLD& leftHalf, CDLLD& rightHalf);
    int countNodes();
    void displayReverse();
    bool isSorted () const;
    bool removeLastNode (int& val);
    bool removeSecondLastNode (int& val);
    bool removeKthNode (int k, int& val);
    void displayCDLLD();
    
    bool  merge(CDLLD& list1, CDLLD& list2);
};

