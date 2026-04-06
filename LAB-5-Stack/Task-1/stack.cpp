#include "stack.h"
#include <iostream>
using namespace std;
stack::stack()
{
    maxSize = 50;
    currSize = 0;
    top = -1;
    st = new int[maxSize];
}
stack::stack(int s)
{
    maxSize = s;
    currSize = 0;
    st = new int[maxSize];
    top = -1;
}
bool stack::isEmpty()
{
    if (currSize == 0)
        return true;
    else
        return false;
}
bool stack::isFull()
{
    if (currSize == maxSize)
        return true;
    else
        return false;
}
stack::~stack()
{
    if (st != nullptr)
    {
        delete[] st;
        st = nullptr;
    }
}
bool stack::push(int val)
{
    if (isFull())
    {
        return false;
    }
    else
    {
        top++;
        st[top] = val;
        currSize++;
        return true;
    }
}
bool stack::pop(int &val)
{
    if (isEmpty())
    {
        return false;
    }
    else
    {
        val = st[top];
        top--;
        currSize--;
        return true;
    }
}
bool stack::getTop(int &val)
{
    if (isEmpty())
        return false;
    else
    {
        val = st[top];
        return true;
    }
}