//Umar Draz - ITM036 - Morning
#include<iostream>
using namespace std;
int printVertical(int val) {
    if (val==0) {
        return 0;
    }
    else{
        
        printVertical(val/10);
        cout<<val%10<<endl;
    }
}
int main() {
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    printVertical(num);
}