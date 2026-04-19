#include<iostream>
using namespace std;

int sum(int a, int b) {
    return a + b;
}
    int main() {
    int num1, num2;
    cout << "Enter two integers: ";
    cin >> num1 >> num2;        
    int result = sum(num1, num2);
    cout << "The sum is: " << result << endl;
    return 0;
}


