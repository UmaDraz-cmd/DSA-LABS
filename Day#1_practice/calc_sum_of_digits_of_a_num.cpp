#include<iostream>
using namespace std;
int SumOfDigits(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10; // Add the last digit to sum
        num /= 10;       // Remove the last digit
    }
    return sum;
}
int main() {
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;        
    int result = SumOfDigits(number);
    cout << "The sum of the digits of " << number << " is: " << result << endl;
    return 0;
}