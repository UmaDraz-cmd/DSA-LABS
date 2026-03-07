#include"unsortedList.h"
#include<iostream>
using namespace std;
int main() {
    unsortedList list(5);
    unsortedList list2(2);
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
        cout<<"Value was not inserted successfully"<<endl;.
    }
    list.display(); 
    int maxVal=0;
    if(list.removeMax(maxVal) ){
        cout<<"MaxVal removed successfully: "<<endl;

    }
    else {
        cout<<"list was empty :"<<endl;
    }
    list.display();
    if(list2.insert(15)) {
        cout<<"Value inserted successfully"<<endl;
    }

    else {
        cout<<"Value was not inserted successfully"<<endl;
    }
    if(list2.insert(10)) {
        cout<<"Value inserted successfully"<<endl;
    }
    else {
        cout<<"Value was not inserted successfully"<<endl;
    }
    list.combineList(list2);
    
}
