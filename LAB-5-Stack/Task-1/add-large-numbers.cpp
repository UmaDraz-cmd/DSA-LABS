#include <iostream>
#include "stack.h"
using namespace std;

void addingLargeNumbers(char num1[], char num2[])
{
    stack stack1, stack2, resultStack;
    int carry = 0;

    int i = 0;
    while (num1[i] != '\0')
    {
        stack1.push(num1[i] - '0'); 
        i++;
    }
    i = 0;
    while (num2[i] != '\0')
    {
        stack2.push(num2[i] - '0');
        i++;
    }

    while (!stack1.isEmpty() || !stack2.isEmpty())
    {
        int sum = carry;
        if (!stack1.isEmpty())
        {
            int digit;
            stack1.pop(digit);
            sum += digit;
        }
        if (!stack2.isEmpty())
        {
            int digit;
            stack2.pop(digit);
            sum += digit;
        }
        resultStack.push(sum % 10);
        carry = sum / 10;
    }
    if (carry != 0)
        resultStack.push(carry);

    while (!resultStack.isEmpty())
    {
        int digit;
        resultStack.pop(digit);
        cout << digit;
    }
    cout << endl;
}