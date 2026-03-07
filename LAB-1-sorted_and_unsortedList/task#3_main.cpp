#include"sortedList.h"
#include<iostream>
using namespace std;
int main() {
    sortedList list(5);
    if(list.insert(15)) {
        cout<<"Value inserted successfully"<<endl;
    }

    else {
        cout<<"Value was not inserted successfully"<<endl;  
    }
    if(list.insert(10)) {
        cout<<"Value inserted successfully"<<endl;
    }
    else {
        cout<<"Value was not inserted successfully"<<endl;  
    }
    if(list.insert(19)) {
        cout<<"Value inserted successfully"<<endl;  
    }
    else {
        cout<<"Value was not inserted successfully"<<endl;  
    }
    if(list.insert(11)) {
        cout<<"Value inserted successfully"<<endl;  
    }
    else {
        cout<<"Value was not inserted successfully"<<endl;  
    }
    if(list.insert(17)) {
        cout<<"Value inserted successfully"<<endl;  
    }
    else {
        cout<<"Value was not inserted successfully"<<endl;  
    }
    list.display();
    int val=19;
    if(list.binarySearch(val)) {
        cout<<"Val found"<<endl;
    }
    else {
        cout<<"Val wasn't found:"<<endl;
    }



}
