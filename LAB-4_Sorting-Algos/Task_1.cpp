#include<iostream>
#include<cstring>
using namespace std;

bool findKthLargest ( int* arr, int n, int k, int& val) {
    if (k < 1 || k > n) {
        return false; // Invalid value of k
    }

    
    for (int i = 0; i < k; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            int temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
                
        }
    }
    val = arr[k - 1]; 
    return true;
}
int main() {
    int arr[] = {3, 1, 4, 5, 2,};
    int n = 5;
    int k = 3;
    int val;

    if (findKthLargest(arr, n, k, val)) {
        cout << "The " << k << "nd largest element is: " << val << endl;
    } else {
        cout << "Invalid value of k." << endl;
    }

    return 0;
}
