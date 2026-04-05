#include<iostream>
#include<algorithm>
using namespace std;
void bubbleSort(int*a, int n) {
    for(int i= n-1; i>=1; i--) {
        for(int j=0; j<i; j++) {
            if(a[j]<a[j+1]) //for descending order 
            {
                swap(a[j],a[j+1]);
            }
        }
    }
}
void selectinSort(int *a, int n) {
    int min=0;
    for(int i=0; i<n-1; i++) {
        min=i;
        for(int j=i+1; j<n; j++) {
            if(a[j]<a[min]) {
                min= j;
            }
        }
        swap(a[min],a[i]);
    }
}
void insertionSort(int *a, int n) {
    int j=0, val=0;
    for(int i=0; i<n; i++) {
        val= a[i];
        j= i-1;
        while(j>=0 && val<a[j]) {
            a[j+1]= a[j];
            j--;
        }
        a[j+1]= val;

    }
}
int main() {
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int* arr = new int[size];
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<size; i++) {
        cin>>arr[i];
     }
    // bubbleSort(arr, size);
    // selectinSort(arr, size);
    insertionSort(arr, size);
    cout<<"The sorted array is: ";
    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
}