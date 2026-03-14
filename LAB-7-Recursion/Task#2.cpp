//Umar Draz Bitf24m036- morning
#include<iostream>
using namespace std;
void printZigZag(int* arr, int start, int end)
{
    if(start > end)
        return;

    if(start == end)
    {
        cout << arr[start] << " ";
        return;
    }

    cout << arr[start] << " ";
    cout << arr[end] << " ";

    printZigZag(arr, start + 1, end - 1);
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
    printZigZag(arr, 0, size - 1);
    delete[] arr;
}