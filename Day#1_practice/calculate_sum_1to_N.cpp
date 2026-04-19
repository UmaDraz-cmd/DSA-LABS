#include<iostream>
using namespace std;
int sum(int a, int n) {
    int sum=0;
    for(int i=a; i<=n; i++) {
        sum += i;
    }
    return sum;
    
}
int main() {
    int N;
    cout << "Enter a positive integer N: ";
    cin >> N;        
    int result = sum(1, N);
    cout << "The sum from 1 to " << N << " is: " << result << endl;
    return 0;
}