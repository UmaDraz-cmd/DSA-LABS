//Umar Draz - ITM036 - Morning
#include<iostream>
using namespace std;
//decreasing pyramid pattern of character
void printChar( char ch, int n) {
    if (n==0) {
        return;
    }
    else{     
        printChar(ch, n-1);
        

        printChar(ch, n-1);
        cout<<ch;
        cout<<endl;
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
