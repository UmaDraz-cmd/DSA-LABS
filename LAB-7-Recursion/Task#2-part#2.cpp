//Umar Draz - ITM036 - Morning
#include<iostream>
using namespace std;
void printZigZagUpdated(int* pStart, int* pEnd)
{
    if(pStart > pEnd)
        return;

    if(pStart == pEnd)
    {
        cout << *pStart << " ";
        return;
    }

    cout << *pStart << " ";
    cout << *pEnd << " ";

    printZigZagUpdated(pStart + 1, pEnd - 1);
}
int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int* arr = new int[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << "The zig-zag order of the array is: ";
    printZigZagUpdated(arr, arr + size - 1);
    delete[] arr;
}