#include<iostream>
using namespace std;
void extract_duplicates(int *arr, int size) {
    int dup=0;
    for(int i=0; i<size; i++ ) {
        for(int j=0; j<size; j++) {
            if(arr[i] == arr[j] && i!=j) {
                
                cout<<arr[i]<<" ";
                break;
                
                
            }
        }
        
    }
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
    cout << "The duplicate elements in the array are: ";
    extract_duplicates(arr, size);
    delete[] arr;
    return 0;
}