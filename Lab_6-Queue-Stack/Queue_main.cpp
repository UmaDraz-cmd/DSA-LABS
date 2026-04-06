#include<iostream>
#include "Queue.h"
using namespace std;
int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Queue contents: ";
    while (!q.isEmpty())
    {
        int value;
        q.dequeue(value);
        cout << value << " ";
    }
    cout << endl;

    return 0;
}