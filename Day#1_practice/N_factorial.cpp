#include<iostream>
using namespace std;
int Factorial(int a, int n) {
    int Factorial=1;
    for(int i=a; i<=n; i++) {
        Factorial *= i;
    }
    return Factorial;
    
}
int main() {
    int N;
    cout << "Enter a positive integer N: ";
    cin >> N;        
    int result = Factorial(1, N);
    cout << "The Factorial from 1 to " << N << " is: " << result << endl;
    return 0;
}