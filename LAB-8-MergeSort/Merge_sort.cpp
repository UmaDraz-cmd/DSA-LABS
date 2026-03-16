#include<iostream>
using namespace std;
void mergeSort(int *arr, int start, int end) {
    if(start >= end) {
        return;
    }
    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    // Merge the two halves
    int *temp = new int[end - start + 1];
    int i = start, j = mid + 1, k = 0;
    while(i <= mid && j <= end) {
        if(arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid) {
        temp[k++] = arr[i++];
    }
    while(j <= end) {
        temp[k++] = arr[j++];
    }
    for(i = start; i <= end; i++) {
        arr[i] = temp[i - start];
    }
    delete[] temp;
}
int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int *arr = new int[size];       
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    mergeSort(arr, 0, size - 1);
    cout << "Sorted array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;   
}
