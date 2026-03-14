//Umar Draz - ITM036 - Morning
#include<iostream>
using namespace std;
// int findLargestIndex(int* arr, int start , int end) {

// }
int findLargestIndex(int* arr, int start, int end)
{
    if (start == end)
        return start;

    int maxIndex = findLargestIndex(arr, start + 1, end);

    if (arr[start] > arr[maxIndex])
        return start;
    else
        return maxIndex;
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
    int largestIndex = findLargestIndex(arr, 0, size - 1);
    cout << "The index of the largest element is: " << largestIndex << endl;
    delete[] arr;
}