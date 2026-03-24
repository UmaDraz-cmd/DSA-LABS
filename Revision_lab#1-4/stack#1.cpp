#include<iostream>
using namespace std;
void printChar( char ch, int n) {
    if (n==0) {
        return;
    }
    else{
        //cout<<"*";
        printChar(ch, n-1);
        cout<<ch;
        
    }
}   

int main() {
    int num;
    char ch;
    cout<<"Enter a character: ";
    cin>>ch;
    cout<<"Enter a number: ";
    cin>>num;
    printChar(ch, num);

}