#include<iostream>
#include "Task#1.h"
using namespace std;


Deque::Deque(int n)
{   
    maxSize = n;
    if (n > 0)
    {
        q = new int[n];
    }
    else
    {
        q = nullptr;
    }
    currSize = 0;
    front = 0;
    back = -1;
}
// ~Deque () Destructor to destroy the Deque. 
Deque::~Deque()
{
    if (q != nullptr)
    {
        delete[] q;
        q = nullptr;
    }
}
Deque::Deque(const Deque &other)
{
    maxSize = other.maxSize;    
    currSize = other.currSize;
    front = other.front;
    back = other.back;
    if (other.q != nullptr)
    {
        q = new int[maxSize];
        for (int i = 0; i < maxSize; i++)
        {            q[i] = other.q[i];
        }
    }
    else
    {
        q = nullptr;
    }   
}
//bool isEmpty () returns true if the Deque is empty, and false otherwise. 
bool Deque::isEmpty() const
{
    if (currSize == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// bool isFull () returns true if the Deque is full, and false otherwise.
bool Deque::isFull() const
{    if (currSize == maxSize)
    {
        return true;
    }
    else
    {     return false;
    }           

}
// void display () to display the elements of Deque from front to back. 
void Deque::display()
{
    if (isEmpty())
    {
        cout << "Deque is empty." << endl;
        return;
    }
    cout << "Deque contents: ";
    for (int i = 0; i < currSize; i++)
    {
        int index = (front + i) % maxSize;
        cout << q[index] << " ";
    }
    cout << endl;
}
// void makeEmpty () to make the Deque empty.
void Deque::makeEmpty()
{
    currSize = 0;
    front = 0;          
    back = -1;
}
// bool insertAtFront (int val) to insert an element at the front of the Deque. It returns true if the insertion is successful, and false if the Deque is full.
bool Deque::insertAtFront(int val)
{
    if (isFull())
    {
        return false;
    }
    else
    {
        front = (front - 1 + maxSize) % maxSize; // Move front backward
        q[front] = val;
        currSize++;
        return true;
    }
}
// bool insertAtBack (int val) to insert an element at the back of the Deque. It returns true if the insertion is successful, and false if the Deque is full.   
bool Deque::insertAtBack(int val)
{
    if (isFull())
    {
        return false;
    }
    else
    {
        back = (back + 1) % maxSize; // Move back forward
        q[back] = val;
        currSize++;
        return true;
    }
}
// bool removeFromFront (int &val) to remove an element from the front of the Deque and store it in the variable val. It returns true if the removal is successful, and
// false if the Deque is empty.
bool Deque::removeFromFront(int &val)
{
    if (isEmpty())
    {
        return false;
    }
    else
    {
        
    }
}
// bool removeFromBack (int &val) to remove an element from the back of the Deque and store it in the variable val. It returns true if the removal is successful, and
// false if the Deque is empty.
bool Deque::removeFromBack(int &val)
{       
    if (isEmpty())
    {
        return false;
    }
    else
    {


        
    }
}




