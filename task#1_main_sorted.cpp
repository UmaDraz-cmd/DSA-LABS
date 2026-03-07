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
    list.display();
    int idx=2, newVl=45;
    if(list.replace(idx,newVl))
    {
        cout<<"REplaced successfully;"<<endl;
    }
    else {
        cout<<"Couldn't be replaced successfully: "<<endl;
    }
    list.display();

}