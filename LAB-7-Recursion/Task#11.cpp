#include<iostream>
using namespace std;
int remainder(int num, int den) {
    int count=0;
    if(count==1) {
        return;
    }
    else {
        count++;
        int rem= remainder(num, den);
        return rem;
    }
}
int main() {
    int num, den;
    cout<<"Enter a number: ";
    cin>>num;
    cout<<"Enter a denominator: ";
    cin>>den;
    cout<<"The remainder is: "<<remainder(num, den);
}