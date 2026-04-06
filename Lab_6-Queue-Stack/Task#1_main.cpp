#include<iostream>
#include "Task#1.h"
using namespace std;
int main() {
    Deque D(40);
    
    D.insertAtFront(3);
    D.insertAtBack(20);
    D.insertAtBack(30);
    D.insertAtBack(40);
    D.insertAtFront(50);

    // cout << "Deque contents: ";
    // while (!D.isEmpty())
    // {
    //     int value;
    //     D.removeFromBack(value);
    //     cout << value << " ";
    // }
    // cout << endl;
    D.display(); 
        // D.removeFromFront(3);
        // D.removeFromBack(40);
        // D.display();
        // D.makeEmpty();
        // D.display();





return 0;
}



// 1. Insert value at Front 
// 2. Insert value at Back 
// 3. Remove value from Front 
// 4. Remove value from Back 
// 5. Display the Deque 
// 6. Make the Deque Empty 
// 7. Exit 
 
// Enter your choice: 
//create the above menu driven program to test the Deque class.



    