#include "LinkedList.h"
#include <iostream>
using namespace std;

int LinkedList::findMin(Node *head)
{
    if(head==nullptr)
    {
        return -1;
    }
    else if(head->next==nullptr)
    {
        return head->data;
    }
    else
    {
        int val=findMin(head->next);
        if(head->data<val)
        {
            return head->data;
        }
        else
        {
            return val;
        }
    }

}

int LinkedList::countEven(Node *head)
{
    if(head==nullptr)
    {
        return 0;
    }
   else if(head->next==nullptr)
    {
        if(head->data%2==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if(head->data%2==0)
        {
            return 1+countEven(head->next);
        }
        else
        {
            return countEven(head->next);
        }
    }

}

LinkedList::LinkedList()
{
    head = nullptr;
}

void LinkedList::unSortedInsert(int val) {
    if (head == nullptr) {
        head = new Node;
        head->data = val;
        head->next=nullptr;
    } else {
        Node* temp = new Node;
        temp->data = val;
        temp->next = head;
        head = temp;
    }
}

void LinkedList::SortedInsert(int val)
{
    Node* temp=head;
    Node* node=new Node;
    node->data=val;
    Node* prev=nullptr;
    while(temp!=nullptr && temp->data<val)
    {
        prev=temp;
        temp=temp->next;
    }
    if(prev==nullptr)
    {
        if(temp==nullptr)
        {
        head=node;
        head->next=nullptr;
        node=nullptr;
        }
        else
        {
            node->next=head;
            head=node;
        }
       
    }
    else
    {
        prev->next=node;
        node->next=temp;
    }
}
void LinkedList::display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    
}

int LinkedList::findMax() {
    if (head == nullptr) {
        return -999;
    } else {
        int maxVal = head->data;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data > maxVal) {
                maxVal = temp->data;
            }
            temp = temp->next;
        }
        return maxVal;
    }
}

bool LinkedList::search(int key) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void LinkedList::displayReverse() {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        temp = temp->next;
        count++;
    }
    while (count != 0) {
        temp = head;
        for (int i = 0; i < count - 1; i++) {
            temp = temp->next;
        }
        cout << temp->data << " ";
        count--;
    }
}
LinkedList::~LinkedList()
{
    Node* temp=head;
    while(head!=nullptr)
    {
        head=head->next;
        delete temp;
        temp=head;
    }
}
LinkedList::LinkedList(const LinkedList &other)
{
    if(other.head==nullptr)
    {
        head=nullptr;
    }
    else
    {
        Node* p1=other.head->next;
        head=new Node;
        head->data=other.head->data;
        Node* p2=head;
        while(p1!=nullptr)
        {
            Node* temp=new Node;
            temp->data=p1->data;
            p2->next=temp;
            p1=p1->next;
            p2=p2->next;

        }
        p2->next=nullptr;
    }
}
LinkedList &LinkedList::operator=(const LinkedList &other)
{
    if(&other==this)
    {
        return *this;
    }
    else if(other.head==nullptr)
    {
        Node* temp=head;
        while(head!=nullptr)
        {
            head=head->next;
            delete temp;
            temp=head;
        }
        
    }
    else
    {
        Node* temp=head;
        while(head!=nullptr)
        {
            head=head->next;
            delete temp;
            temp=head;
        }
        Node* p1=other.head->next;
        head=new Node;
        head->data=other.head->data;
        Node* p2=head;
        while(p1!=nullptr)
        {
            Node* newNode=new Node;
            newNode->data=p1->data;
            p2->next=newNode;
            p1=p1->next;
            p2=p2->next;

        }
        p2->next=nullptr;

    }
    return *this;
    
}
int LinkedList::findMin()
{
    return findMin(head);

}
int LinkedList::countEvens()
{
    return countEven(head);
}
void LinkedList::splitlinklist(LinkedList &l1, LinkedList &l2)
{
    if(head!=nullptr)
    {
        Node* t1=l1.head=head;
        Node* t2=l2.head=head->next;
        int count=0;
        Node* temp=t2->next;
        while(temp!=nullptr)
        {
            if(count==0 || count%2==0)
            {
                t1->next=temp;
                t1=t1->next;
            }
            else
            {
                t2->next=temp;
                t2=t2->next;
            }
            temp=temp->next;
            count++;
        }
        head=t2->next=t1->next=nullptr;
        
    }
}
bool LinkedList::unSortedRemove(int val)
{
    Node* curr=head;
    Node* prev=nullptr;
    while(curr!=nullptr && curr->data!=val)
    {
        prev=curr;
        curr=curr->next;
    }
    if(curr!=nullptr)
    {
        if(prev==nullptr)
        {
            head=head->next;
        }
        else
        {
            prev->next=curr->next;
        }
        
        delete curr;
        curr=nullptr;
        return true;
    }
    else
    {
        return false;
    }
}
bool LinkedList::sortedRemove(int val)
{
    Node* curr=head;
    Node* prev=nullptr;
    while(curr!=nullptr && curr->data<val)
    {
        prev=curr;
        curr=curr->next;
    }
    if(curr!=nullptr && curr->data==val)
    {
        if(prev==nullptr)
        {
            head=head->next;
        }
        else
        {
            prev->next=curr->next;
        }       
        delete curr;
        curr=nullptr;
        return true;
    }
    else
    {
        return false;
    }
}
