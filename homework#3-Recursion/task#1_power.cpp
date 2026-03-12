#include<iostream>
using namespace std;
int power(int a, int n) {
    if(n==0) {
        return 1; // Base case: any number to the power of 0 is 1
    }
    int temp= power(a, n-1); // Recursive call with n decremented by 1
    return a * temp; // Multiply a with the result of a to the power of (n-1)
}
int main() {
    int base, exponent;
    cout << "Enter base and exponent: ";
    cin >> base >> exponent;        
    cout << "Result: " << power(base, exponent) << endl;
    return 0;
}