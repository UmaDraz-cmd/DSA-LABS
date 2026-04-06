#include "stack.cpp"
#include "add-large-numbers.cpp"
#include "stack.h"
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    char num1[41], num2[41];
    cout << "Enter the first number (max 40 digits): ";
    cin >> num1;
    cout << "Enter the second number (max 40 digits): ";
    cin >> num2;

    if (strlen(num1) > 40 || strlen(num2) > 40)
    {
        cout << "Input exceeds maximum allowed length (40 digits)." << endl;
        return 1;
    }
    cout << "Sum : ";
    addingLargeNumbers(num1, num2);
    return 0;
}