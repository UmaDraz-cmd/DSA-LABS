#include<iostream>
#include "Stack.h"
using namespace std;
int main()
{
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << "Stack contents: ";
    while (!s.isEmpty())
    {
        int value;
        s.pop(value);
        cout << value << " ";
    }
    cout << endl;

    return 0;
    
}