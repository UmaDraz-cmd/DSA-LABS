#include<iostream>
using namespace std;
// function to convert decimal to binary
void  decim_to_binary(int n) {
    if(n==0) {
        return; // Base case: if n is 0, return
    }
    decim_to_binary(n/2); // Recursive call with n divided by 2
    cout << n % 2; // Print the remainder (0 or 1)
}

int main() {
    int decimal;
    cout << "Enter a decimal number: ";
    cin >> decimal;
    cout << "Binary equivalent: ";
    decim_to_binary(decimal);
    cout << endl;
    return 0;
}