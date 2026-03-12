#include<iostream>
using namespace std;
// Function to calculate factorial recursively
int factorial(int n) {
    if(n==0) {
        return 1; // Base case: factorial of 0 is 1
    }
    int temp= factorial(n-1); // Recursive call
    return n * temp; // Multiply n with the factorial of (n-1)
}
int main() {
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;
    
    if(number < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        cout << "Factorial of " << number << " is " << factorial(number) << endl;
    }
    
    return 0;
}