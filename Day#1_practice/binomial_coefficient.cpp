#include<iostream>
using namespace std;
int binomial_coefficient(int n, int r) {
int fact1=1,fact2=1,fact3=1;
for(int i=1;i<=n;i++) {
    fact1 *= i;
}
for(int i=1;i<=r;i++) {
    fact2 *= i;
}
for(int i=1;i<=(n-r);i++) {
    fact3 *= i;
}
// int binomial_coefficient(int n, int r) {
    return fact1/(fact2*fact3);
}

int main() {
    int n, r;
    cout << "Enter values for n and r (n >= r >= 0): ";
    cin >> n >> r;        
    if(r > n || r < 0) {
        cout << "Invalid input. Please ensure that n >= r >= 0." << endl;
        return 1;
    }
    int result = binomial_coefficient(n, r);
    cout << "The Binomial Coefficient C(" << n << ", " << r << ") is: " << result << endl;
    return 0;
}       