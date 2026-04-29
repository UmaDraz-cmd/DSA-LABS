#include "CDLLD.h"
#include <iostream>
using namespace std;
CDLLD::CDLLD()
{
    head.next = head.prev = &head;
}

CDLLD::~CDLLD()
{
    DNode *curr = head.next;
    while (curr != &head)
    {
        DNode *temp = curr;
        curr = curr->next;
        delete temp;
    }
    head.next = head.prev = &head;
}

bool CDLLD::insertAtStart(int val)
{
    DNode *temp = new DNode;
    temp->data = val;
    temp->next = head.next;
    temp->prev = &head;
    head.next = temp;
    temp->next->prev = temp;
    return true;
}

bool CDLLD::insertAtEnd(int val)
{
    DNode *temp = new DNode;
    temp->data = val;
    temp->next = &head;
    temp->prev = head.prev;
    head.prev->next = temp;
    head.prev = temp;
    return true;
}
CDLLD::CDLLD(const CDLLD &other)
{
    DNode *temp1 = other.head.next;
    DNode *temp2 = &head;
    while (temp1 != &other.head)
    {
        temp2->next = new DNode;
        temp2->next->data = temp1->data;
        temp2->next->prev = temp2;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp2->next = &head;
    head.prev = temp2;
}
bool CDLLD::sortedInsert(int val)
{
    DNode *curr = head.next;
    while (curr != &head && curr->data < val)
    {
        curr = curr->next;
    }
    DNode *temp = new DNode;
    temp->data = val;
    temp->next = curr;
    temp->prev = curr->prev;
    curr->prev = temp;
    temp->prev->next = temp;
    return true;
}
bool CDLLD::sortedRemove(int val)
{
    DNode *curr = head.next;
    while (curr != &head && curr->data < val)
    {
        curr = curr->next;
    }
    if (curr != &head && curr->data == val)
    {

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        return true;
    }
    else
    {
        return false;
    }
}
bool CDLLD::unsortedRemove(int val)
{
    DNode *curr = head.next;
    while (curr != &head && curr->data != val)
    {
        curr = curr->next;
    }
    if (curr != &head)
    {

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        return true;
    }
    else
    {
        return false;
    }
}
void CDLLD::combine(CDLLD &list1, CDLLD &list2)
{
    if (list1.head.next == &(list1.head) && list2.head.next == &(list2.head))
    {
        head.prev = head.next = &head;
    }
    else if(list2.head.next==&(list2.head))
    {
        head.next=list1.head.next;
        head.prev=list1.head.prev;
        list1.head.prev->next=&head;
        list1.head.next->prev=&head;
        list1.head.next = &(list1.head);
        list1.head.prev = &(list1.head);
    }
    else if(list1.head.next==&(list1.head))
    {
        head.next=list2.head.next;
        head.prev=list2.head.prev;
        list2.head.prev->next=&head;
        list2.head.next->prev=&head;
        list2.head.next = &(list2.head);
        list2.head.prev = &(list2.head);
    }
    else 
    {
        list1.head.prev->next = list2.head.next;
        list2.head.next->prev = list1.head.prev;
        head.next = list1.head.next;
        list1.head.next->prev = &head;
        head.prev = list2.head.prev;
        list2.head.prev->next = &head;
        list1.head.next = &(list1.head);
        list1.head.prev = &(list1.head);
        list2.head.next = &(list2.head);
        list2.head.prev = &(list2.head);
    }
    
}
void CDLLD::shuffleMerge(CDLLD &list1, CDLLD &list2)
{
    DNode* temp1=list1.head.next;
    DNode* temp2=list2.head.next;
    DNode* temp3=&head;
    while(temp1!=&list1.head)
    {
        temp3->next=temp1;
        temp1->prev=temp3;
        temp3=temp1;
        temp1=temp1->next;
        temp3->next=temp2;
        temp2->prev=temp3;
        temp3=temp2;
        temp2=temp2->next;
    }
    temp3->next=&head;
    head.prev=temp3;
    list1.head.next=list1.head.prev=&(list1.head);
    list2.head.next=list2.head.prev=&(list2.head);
}
void CDLLD::splitList(CDLLD &leftHalf, CDLLD &rightHalf)
{
    int count=this->countNodes();
    DNode* temp3=head.next;
    int left=0;
    if(count%2==0)
    {
        left=count/2;
    }
    else 
    {
        left=count/2+1;
    }
    leftHalf.head.next=temp3;
    temp3->prev=&(leftHalf.head);
    int counting=0;
    while(counting!=left)
    {
        counting++;
        temp3=temp3->next;        
    }
    DNode* hold=temp3->prev;
    temp3->prev->next=&(leftHalf.head);
    leftHalf.head.prev=hold;
    rightHalf.head.next=temp3;
    temp3->prev=&(rightHalf.head);
    rightHalf.head.prev=head.prev;
    rightHalf.head.prev->next=&(rightHalf.head);
    head.prev=head.next=&(head);   

}
int CDLLD::countNodes()
{
    DNode* curr=head.next;
    int count=0;
    while(curr!=&head)
    {
        count++;
        curr=curr->next;
    }
    return count;
}
void CDLLD::displayReverse()
{
    DNode* curr=head.prev;
    while(curr!=&head)
    {
        cout<<curr->data<<" ";
        curr=curr->prev;
    }
}
bool CDLLD::isSorted() const
{
    if(head.next==&head)
    {
        return false;
    }
    DNode* prev=head.next;
    DNode* curr=head.next->next;
    while(curr!=&head)
    {
        if(curr->data<prev->data)
        {
            return false;
        }
        else
        {
            prev=curr;
            curr=curr->next;
        }
    }
    return true;
}
bool CDLLD::removeLastNode(int &val)
{
    if(head.next==&head)
    {
        return false;
    }
    else
    {
        DNode* temp=head.prev;
        val=temp->data;
        temp->prev->next=&head;
        head.prev=temp->prev;
        delete temp;
        temp=nullptr;
        return true;
    }
   
}
bool CDLLD::removeSecondLastNode(int &val)
{
   int count=this->countNodes();
   if(count<2)
   {
        return false;
   }
   else
   {
        DNode* temp=head.prev->prev;
        val=temp->data;
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
        temp=nullptr;
        return true;
   }    
}
bool CDLLD::removeKthNode(int k, int &val)
{
    int count=1;
    DNode* temp=head.next;
    while(temp!=&head && count<k)
    {
        temp=temp->next;
        count++;
    }
    if(temp==&head)
    {
        return false;
    }
    else
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        val=temp->data;
        delete temp;
        temp=nullptr;
        return true;
    }


}
void CDLLD::displayCDLLD()
{
    DNode *curr = head.next;
    while (curr != &head)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
