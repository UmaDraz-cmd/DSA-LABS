#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            return mid;   // element found
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;  // search right half
        }
        else
        {
            high = mid - 1; // search left half
        }
    }

    return -1; // element not found
}

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72};
    int size = 9;

    int key;
    cout << "Enter number to search: ";
    cin >> key;

    int result = binarySearch(arr, size, key);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}