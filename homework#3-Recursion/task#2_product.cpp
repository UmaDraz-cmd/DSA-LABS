#include<iostream>
using namespace std;
int product(int a, int b) {
    if(b==0 ) {
        return 0;
    }
    else {
        int pro= product(a, b-1); // Recursive call with b decremented by 1
        return a + pro; // Add a to the product of a and (b-1)
    }
}
int main() {
    int num1, num2;
    cout << "Enter two integers: ";
    cin >> num1 >> num2;
    
    int result = product(num1, num2);
    cout << "Product of " << num1 << " and " << num2 << " is: " << result << endl;
    
    return 0;
}