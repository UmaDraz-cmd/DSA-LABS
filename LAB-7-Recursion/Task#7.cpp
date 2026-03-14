#include<iostream>
using namespace std;
//Umar Draz - ITM036 - Morning
bool areArraysEqual(int* a, int aSize, int* b, int bSize)
{
    if(aSize != bSize)
        return false;

    if(aSize == 0)
        return true;

    if(a[0] != b[0])
        return false;

    return areArraysEqual(a + 1, aSize - 1, b + 1, bSize - 1);
}
int main() {
    int sizeA, sizeB;
    cout << "Enter the size of the first array: ";
    cin >> sizeA;
    int* arrA = new int[sizeA];
    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < sizeA; i++) {
        cin >> arrA[i];
    }
    cout << "Enter the size of the second array: ";
    cin >> sizeB;
    int* arrB = new int[sizeB];
    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < sizeB; i++) {
        cin >> arrB[i];
    }
    if(areArraysEqual(arrA, sizeA, arrB, sizeB))
        cout << "The arrays are equal." << endl;
    else
        cout << "The arrays are not equal." << endl;

    delete[] arrA;
    delete[] arrB;
}
