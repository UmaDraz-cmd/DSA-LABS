#include "CDLLD.cpp"
#include<iostream>
#include<stack>
#include<list>
using namespace std;
int main()
{
    // CDLLD l1;
    // l1.sortedInsert(5);
    // l1.sortedInsert(6);
    // l1.sortedInsert(7);
    // l1.sortedInsert(1);
    CDLLD l2;
    l2.insertAtEnd(1);
    l2.insertAtEnd(4);
    l2.insertAtEnd(12);
    l2.insertAtEnd(91);
    l2.insertAtEnd(111);
    l2.insertAtEnd(500);
    int val=0;
    l2.removeKthNode(3,val);
    l2.displayCDLLD();
    // int val=0;
    // cout<<l2.removeSecondLastNode(val)<<endl;
    // cout<<val<<endl;
    // cout<<l2.removeSecondLastNode(val)<<endl;
    // cout<<val<<endl;
    // cout<<l2.removeLastNode(val)<<endl;
    // cout<<val<<endl;
    // l2.insertAtEnd(3);
    // l2.displayCDLLD();
    // CDLLD l3;
    // CDLLD l4;
    // l2.splitList(l3,l4);
    // l3.displayReverse();
    // cout<<endl;
    // l4.displayReverse();
    // cout<<l2.isSorted();
    // l2.sortedInsert(11);
   
    // l1.displayCDLLD();
    // // CDLLD l2(l1);
    // // l2.displayCDLLD();
    // cout<<"After deletion";
    // // l1.sortedRemove(1);
    // // l1.sortedRemove(5);
    // // l1.sortedRemove(6);
    // // l1.sortedRemove(99);
    // // l1.sortedRemove(7);
    // l1.unsortedRemove(5);
    // l1.unsortedRemove(1);
    // cout<<l1.unsortedRemove(88);
    // l1.displayCDLLD();
    return 0;
}