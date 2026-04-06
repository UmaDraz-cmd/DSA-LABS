#pragma once

class stack
{
private:
    int *st;
    int maxSize, currSize;
    int top;

public:
    stack();
    stack(int s);
    bool isFull();
    bool isEmpty();
    ~stack();
    bool push(int val);
    bool pop(int &val);
    bool getTop(int &val);
};