//Umar Draz - ITM036 - Morning
#include<iostream>
using namespace std;
int linearSearchUpdated(int* arr, int start, int end, int key)
{
    if(start > end)
        return 0;

    if(arr[start] == key)
        return 1 + linearSearchUpdated(arr, start + 1, end, key);
    else
        return linearSearchUpdated(arr, start + 1, end, key);
}

int main()
{
    int size, key;
    cout << "Enter the size of the array: ";
    cin >> size;
    int* arr = new int[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << "Enter the key to search: ";
    cin >> key;
    int count = linearSearchUpdated(arr, 0, size - 1, key);
    cout << "The key " << key << " appears " << count << " times in the array." << endl;
    delete[] arr;
} 