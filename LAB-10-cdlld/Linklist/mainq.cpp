#include "LinkedQueue.h"
#include <iostream>

using namespace std;

int main() {
    LinkedQueue q;

    cout << "--- Test 1: The 'back' Pointer Integrity ---" << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    
    cout << "Expected Output: 10 20 30 40" << endl;
    cout << "Actual Output:   ";
    q.display(); 

    cout << "\n--- Test 2: Value Extraction via Reference ---" << endl;
    int extractedValue = -999; // Default dummy value
    
    if (q.dequeue(extractedValue)) {
        cout << "Expected dequeued value: 10" << endl;
        cout << "Actual dequeued value:   " << extractedValue << endl;
    } else {
        cout << "Dequeue failed." << endl;
    }

    return 0;
}