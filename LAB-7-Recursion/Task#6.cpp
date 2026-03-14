//Umar Draz - ITM036 - Morning
#include<iostream>
using namespace std;
int sumDigits(int num) {
if(num==0) {
    return 0;
}
else {
    return num%10 + sumDigits(num/10);
}
}

int main() {
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    cout<<"The sum of the digits is: "<<sumDigits(num);
}