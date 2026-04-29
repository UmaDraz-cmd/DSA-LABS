#include <iostream>
#include "LinkedList.cpp"
#include "LinkedStack.cpp"
#include "Node.cpp"
using namespace std;

int main() {
    LinkedList l1;
    l1.SortedInsert(2);
    l1.SortedInsert(3);
    l1.SortedInsert(4);
    l1.SortedInsert(12);
    l1.SortedInsert(31);
    l1.SortedInsert(-5);
    cout<<endl;
    cout<<l1.findMin()<<endl;
    cout<<l1.countEvens()<<endl;
    l1.display();
    // cout<<endl;
    // l1.sortedRemove(-5);
    // l1.sortedRemove(2);
    // l1.sortedRemove(4);
    // l1.display();
    // LinkedList l2(l1);
    // cout<<endl;
    // l2.display();
    // LinkedList l3;
    // l3=l1;
    // l1=l1;
    // cout<<endl;
    // l3.display();
    // l1.display();
    // cout << "\nmax " << l1.findMax();
    // cout << "\n" << l1.search(31);
    // cout << "\n" << l1.search(99);
    // cout << endl;
    // l1.displayReverse();
    return 0;
}