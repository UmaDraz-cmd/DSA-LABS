#include<iostream>
using namespace std;
int linearSearch(int *a, int start, int end, int key) {
    int count=0;
    if(start>end) {
        return count;
    }
    else if(a[start]==key) {
        count++;
    }
    else {
        return linearSearch(a, start+1, end, key);

    }
}
int main() {
    
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
    int idx = linearSearch(arr, 0, size - 1, key);
    cout << "The key " << key << " appears at idx: " << idx<< "  in the array." << endl;
    delete[] arr;
}

// //git add .
// git commit -m "Added task4 recursion problem"
// git push