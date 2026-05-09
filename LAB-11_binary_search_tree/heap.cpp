#include<iostream>
using namespace std;
class MaxHeap {
    private:
        int* h;
        int maxSize, currSize;
    public:
    MaxHeap(int size) {
        maxSize = size;
        currSize = 0;
        h = new int[maxSize];

    }
    ~MaxHeap() {
        delete[] h;
    }
    bool isEmpty() {
        return currSize == 0;
    }
    bool isFull() {
        return currSize == maxSize;
    }
    bool insert(int  val) {
        if(isFull()) {
            return false;
        }
        else {
            currSize++;
            int i=currSize;
            while(i>1 && val > h[i/2]) {
                h[i] = h[i/2];
                i=i/2;
            }
            h[i] = val;
            return true;
        }
    }
    bool removeMax(int &maxVal) {
        if(isEmpty()) {
            return false;
        }
        maxVal = h[1];
        int lastVal = h[currSize];
        currSize--;
        int i=1, j=2*i;
        while(j<=currSize) {
            if(j<currSize && h[j]<h[j+1]) {
                j++;
            }
            if(lastVal >= h[j]) {
                break;
            }
            h[i] = h[j];
            i=j;
            j=2*i;
        }
        h[i] = lastVal;
        return true;
    }
    void display() {
        for(int i=1; i<=currSize; i++) {
            cout<<h[i]<<" ";
        }
        cout<<endl;
    }
};
int main() {
    MaxHeap heap(10);
    heap.insert(5);
    heap.insert(3);
    heap.insert(8);
    heap.insert(1);
    heap.insert(6);
    cout<<"Max Heap: ";
    heap.display();
    int maxVal;
    if(heap.removeMax(maxVal)) {
        cout<<"Removed Max Value: "<<maxVal<<endl;
        cout<<"Max Heap after removal: ";
        heap.display();
    }
    else {
        cout<<"Heap is empty. Cannot remove max value."<<endl;
    }
    return 0;
}