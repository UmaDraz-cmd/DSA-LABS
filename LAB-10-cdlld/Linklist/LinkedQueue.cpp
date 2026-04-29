#include "LinkedQueue.h"
#include<iostream>
using namespace std;
LinkedQueue::LinkedQueue()
{
    front=nullptr;
    back=nullptr;
}

bool LinkedQueue::enqueue(int val)
{
    if(front==nullptr)
    {
        front=back=new Node;
        front->data=val;
        front->next=nullptr;
    }
    else
    {
        Node* newNode=new Node;
        newNode->data=val;
        newNode->next=nullptr;
        back->next=newNode;
        back=newNode;
    }
    return true;
}

bool LinkedQueue::dequeue(int &val)
{
    if(front==nullptr)
    {
        return false;
    }
    else
    {
        Node* temp=front;
        val=temp->data;
        front=front->next;
        delete temp;
        temp=nullptr;
        return true;
    }
}

void LinkedQueue::display()
{
    Node* temp=front;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

LinkedQueue::~LinkedQueue()
{
    Node* temp=front;
    while(front!=nullptr)
    {
        front=front->next;
        delete temp;
        temp=front;
    }
    back=nullptr;
}
